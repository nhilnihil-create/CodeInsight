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
    ll k;
    cin>>k;

    bool flag = true;
    for(ll i=1;i<s.size();++i){
        if(s[i-1] != s[i]){
            flag = false;
            break;
        }
    }
    if(flag){
        ll sum = s.size() * k;
        cout<<sum/2<<endl;
        return 0;
    }

    ll ans = 0;
    ll count = 0;
    string t = s;
    for(ll i=1;i<t.size();++i){
        if(t[i-1] == t[i]){
            t[i] = 'A';
            count++;
        }
    }
    ans += count * k;

    if(s[0] == s[s.size()-1]){
        char now = s[0];
        ll a = 1;
        for(ll i=1;i<s.size();++i){
            if(now == s[i]){
                a++;
            }else{
                break;
            }
        }
        ll b = 0;
        for(ll i=1;i<s.size();++i){
            if(now == s[s.size()-i]){
                b++;
            }else{
                break;
            }
        }
        ans -= (a / 2 + b / 2 - (a + b) / 2) * (k - 1);
    }
    cout<<ans<<endl;

    return 0;
}