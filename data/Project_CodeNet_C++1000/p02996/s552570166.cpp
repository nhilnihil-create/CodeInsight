#include <bits/stdc++.h>
typedef long long int ll;
typedef long double ld;
using namespace std;
const long long int INF = 1e18;
const long long int mod = 1e9+7;

typedef pair<ll, ll> pairs;
typedef vector<pairs> p;

struct edge{
    ll to, cost;
};


ll gcd(ll a,ll b){
    if(b == 0){
        return a;
    }else{
        return gcd(b, a%b);
    }
}

ll lcm(ll a, ll b){
    return a / gcd(a, b) * b;
}

ll keta(ll N){
    int tmp{};
    while( N > 0 ){
        tmp += ( N % 10 );
        N /= 10;
    }
    N = tmp;
    return N;
}

vector<bool> IsPrime;
void sieve(size_t max){
    if(max+1 > IsPrime.size()){
        IsPrime.resize(max+1,true);
    } 
    IsPrime[0] = false;
    IsPrime[1] = false;

    for(size_t i=2; i*i<=max; ++i){
        if(IsPrime[i]){
            for(size_t j=2; i*j<=max; ++j){
                IsPrime[i*j] = false;
            }
        }
    }
}

// 回文
bool kai(string S){
    bool flag = true;
    for(ll i=0;i<S.size()/2;++i){
        if(S[i] != S[S.size()-i-1]){
            flag = false;
            break;
        }
    }
    return flag;
}
// ---------------------------------------------

int main(){
    ll n;
    cin>>n;
    vector<pair<ll, ll> > p(n);
    for(ll i=0;i<n;++i){
        ll a, b;
        cin>>a>>b;
        p[i] = make_pair(b, a);
    }
    sort(p.begin(), p.end());

    string ans = "Yes";
    ll now = p[n-1].first;
    for(ll i=n-1;i>=0;--i){
        now = min(p[i].first - p[i].second, now - p[i].second);
        if(now < 0){
            ans = "No";
            break;
        }
        //cout<<now<<endl;
    }
    cout<<ans<<endl;

    return 0;
}