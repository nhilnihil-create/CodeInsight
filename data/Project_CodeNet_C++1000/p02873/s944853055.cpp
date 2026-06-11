#include <bits/stdc++.h>
typedef long long int ll;
typedef long double ld;
using namespace std;
const long long int INF = 1e18;
const long long int mod = 1e9+7;

typedef pair<ll, ll> pairs;
typedef vector<pairs> p;

struct Edge{
    ll to, weight;
    Edge(ll t, ll w) : to(t), weight(w){}
};
using graph = vector<vector<ll>>;
using Graph = vector<vector<Edge>>;


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
    string s;
    cin>>s;

    vector<ll> a;
    vector<bool> bl;

    char now = s[0];
    ll count = 1;
    for(ll i=1;i<s.size();++i){
        if(now == s[i]){
            count++;
        }else{
            a.push_back(count);
            if(now == '<'){
                bl.push_back(false);
            }else{
                bl.push_back(true);
            }
            now = s[i];
            count = 1;
        }
    }
    a.push_back(count);
    if(now == '<'){
        bl.push_back(false);
    }else{
        bl.push_back(true);
    }

    ll fir = 0;
    ll n = a.size();
    ll ans = 0;
    bool flag;
    for(ll i=0;i<n;++i){
        if(bl[i] == true){
            ans += max(fir, a[i]);
            //cout<<max(fir, a[i])<<endl;
            for(ll j=a[i]-1;j>=1;--j){
                ans += j;
                //cout<<j<<endl;
            }
            fir = 0;
            flag = true;
        }if(bl[i] == false){
            for(ll j=1;j<=a[i];++j){
                //cout<<max(fir+j-1, (ll)0)<<endl;
                ans += max(fir + j - 1, (ll)0);
            }
            fir = fir + a[i];
            flag = false;
        }
    }
    if(flag == false){
        ans += fir;
    }
    cout<<ans<<endl;

    return 0;
}