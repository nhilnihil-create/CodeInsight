//Gathering Children

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define int long long
#define rep(i,x,y) for(ll i=x;i<y;i++)
#define irep(i,a) for(auto i = a.begin(); i != a.end(); ++i)
#define nvarep(n,a) ll n;cin>>n;vector<ll>a(n);rep(i,0,n)cin>>a[i]
#define vecrep(n,a,type) vector<type>a(n);rep(i,0,n)cin>>a[i]
#define lcm(a,b) (a/__gcd(a, b)*b)
#define range(a) (a).begin(),(a).end() 
#define pb push_back
#define mp make_pair
#define nnn "\n"
#define spa " "

using p = pair<ll,string>;
using garph = vector<vector<ll>>;
const int inf = 2147483647;//2*10^9
const ll INF = 9223372036854775807;//9*10^18

signed main (){
    string s;
    cin>>s;
    s.pb('R');
    rep(i,0,s.size()-1){
        int a = i;
        int l = 0,r = 0;
        bool flag = false;
        while(true){
            if(flag&&s[a+l+r]=='R'){
                i--;
                break;
            }
            if(s[a+l+r]=='R')r++;
            else{
                l++;
                flag=true;
            }
            i++;
        }
        rep(j,0,r-1)cout<<0<<spa;
        if((l+r)%2==0)cout<<(l+r)/2<<spa<<(l+r)/2<<spa;
        else if(r%2==0)cout<<(l+r)/2<<spa<<(l+r)/2+1<<spa;
        else cout<<(l+r)/2+1<<spa<<(l+r)/2<<spa;
        rep(j,0,l-1)cout<<0<<spa;
    }
    cout<<nnn;
    return 0;
}