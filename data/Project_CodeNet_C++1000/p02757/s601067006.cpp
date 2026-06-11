#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using vin=vector<int>;
using vll=vector<long long>;
using vvin=vector<vector<int>>;
using vvll=vector<vector<long long>>;
using vstr=vector<string>;
using vvstr=vector<vector<string>>;
using vch=vector<char>;
using vvch=vector<vector<char>>;
using vbo=vector<bool>;
using vvbo=vector<vector<bool>>;
using vpii=vector<pair<int,int>>;
using pqsin=priority_queue<int,vector<int>,greater<int>>;
#define mp make_pair
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep2(i,s,n) for(int i=(s);i<(int)(n);i++)
#define all(v) v.begin(),v.end()
#define decp(n) cout<<fixed<<setprecision((int)n)
const ll inf=1e9+7;
const ll INF=1e18;

int main(){
    int n,p;cin>>n>>p;
    string s;cin>>s;
    ll ans=(ll)0;
    if(p!=2&&p!=5){
        vll r(p);r[0]++;
        int sum=0,res=1,tmp;
        for(int i=n-1;i>=0;i--){
            tmp=s[i]-'0';
            tmp*=res;tmp%=p;
            sum+=tmp;sum%=p;
            r[sum]++;
            res*=10;res%=p;
        }
        rep(i,p)ans+=r[i]*(r[i]-(ll)1)/2;
    }
    else{
        int tmp;
        if(p==2){
            rep(i,n){
                tmp=s[i]-'0';
                if(tmp%2==0)ans+=(ll)(i+1);
            }
        }
        else{
            rep(i,n){
                tmp=s[i]-'0';
                if(tmp==0||tmp==5)ans+=(ll)(i+1);
            }
        }
    }
    cout<<ans<<endl;
}