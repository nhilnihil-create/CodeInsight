//><

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define int long long
#define rep(i,x,y) for(ll i=x;i<y;i++)
#define irep(i,a) for(auto i = a.begin(); i != a.end(); ++i)
#define nvarep(n,a) ll n;cin>>n;vector<ll>a(n);rep(i,0,n)cin>>a[i]
#define vecrep(n,a,type) vector<type>a(n);rep(i,0,n)cin>>a[i]
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a/__gcd(a, b)*b)
#define range(a) (a).begin(),(a).end() 
#define pb push_back
#define mp make_pair
#define nnn "\n"
#define spa " "
#define cout15(a) printf("%.15f\n",a)
template<class T>inline bool chmin(T& a,T b,bool f){
if(f==1){if(a>b){a=b;return true;}return false;}
else if(f==0){if(a<b){a=b;return true;}return false;}return false;}
typedef pair<ll,string> p;
using g = vector<vector<ll>>;
const int inf = 2147483647;//2*10^9
const ll INF = 9223372036854775807;//9*10^18

signed main (){
    string s;cin>>s;
    ll ans = 0;
    if(s[0]=='>'){
        ll c = 0;
        for(int i=0;s[i]=='>';i++){
            c++;
            ans+=c;
        }
        s.erase(0,c);
    }
    if(s[s.size()-1]=='<'){
        ll c = 0;
        for(int i=s.size()-1;s[i]=='<';i--){
            c++;
            ans+=c;
        }
        s.erase(s.size()-c,c);
    }
    s.pb('<');
    while(s.size()!=1){
        bool flag = true;
        int dai=0,sho=0;
        for(int i=0;flag||s[i]!='<';i++){
            if(s[i]=='>'){
                flag=false;
                dai++;
            }else{
                sho++;
            }
        }
        s.erase(0,dai+sho);
        if(dai>sho)sho--;
        else dai--;
        rep(i,1,dai+1)ans+=i;
        rep(i,1,sho+1)ans+=i;
    }
    cout<<ans<<nnn;
    return 0;
}