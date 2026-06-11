#include<bits/stdc++.h>
#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
#define srep(i,n,m) for(int i=n;i<m;i++)
#define elif else if
#define INF 1000000007
using namespace std;
int gcd(int a,int b){
    if(b==0) return a;
    return gcd(b,a%b);
}
int n,b=0,aa[110000],cnt=0;
pair<string,int> p[220000];
string s,ss[220000],x;
char c;
signed main(){
    cin>>n;
    rep(i,n){
        cin>>p[i].first>>p[i].second;
    }
    cin>>x;
    rep(i,n){
        if(b==1){
            cnt+=p[i].second;
        }
        if(p[i].first==x){
            b=1;
        }
    }
    cout<<cnt;
}