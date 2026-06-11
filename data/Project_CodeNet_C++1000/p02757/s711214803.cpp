#include <bits/stdc++.h>
#define REP(i, n) for(long long i = 0; i < n; i++)
#define REPR(i, n) for(long long i = n - 1; i >= 0; i--)
#define FOR(i, m, n) for(long long i = m; i <= n; i++)
#define FORR(i, m, n) for(long long i = m; i >= n; i--)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define VSORTR(v) sort(v.rbegin(), v.rend());
#define ALL(v) (v).begin(),(v).end()
#define FIN ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using P = pair<ll, ll>;
const ll mod = 1e9+7;

ll p;
ll power(ll a,ll b){return b?power(a*a%p,b/2)*(b%2?a:1)%p:1;}


int main(){FIN

    ll n;cin>>n>>p;
    string s;cin>>s;
    map<ll,ll> mp;
    mp[0]++;

    ll dig=0, count=0, ans=0;
    FORR(i,s.size()-1, 0){
        
        if(p==2 || p==5){
            if ((s[i]-'0') % p == 0){
                ans+=(i+1);
            }
            // cout<<ans<<endl;
        }

        else{
            if(i==s.size()-1) dig=s[i]-'0';
            else dig+= (s[i]-'0')*power(10,count);
            
            dig%=p;
            mp[dig]++;
            count++;
        }
        // cout<<dig<<endl;
    }
    if(p==2||p==5){
        cout<<ans<<endl;
        return 0;
    }


    else{
        ll as = 0;
        for(auto p:mp){
            as += p.second * (p.second-1) / 2;
        }
        cout<<as<<endl;
    }

    return 0;
}