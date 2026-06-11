//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pp pair<int,int>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define ld long double
#define al(a) (a).begin(),(a).end()
#define mk make_pair
#define check cout<<"?"<<endl;

ll MOD=1000000007;
ll mod=998244353;
int inf=1000001000;
ll INF=1e18+5;

int main(){
    string s; cin>>s;
    int n=s.size();
    reverse(al(s));
    vector<int> dp_d(n,0),dp_x(n,0);
    rep(i,n){
        if(i==0){
            if(s[i]=='0') dp_d[i]=inf;
            else{
                dp_d[i]=10-(s[i]-'0');
                if(i==n-1) dp_d[i]++;
            }
            dp_x[i]=s[i]-'0';
            continue;
        }
        int d=inf,x=inf;
        d=min(d,dp_d[i-1]+9-(s[i]-'0'));
        if(s[i]!='0') d=min(d,dp_x[i-1]+10-(s[i]-'0'));
        if(s[i]!='9') x=min(x,dp_d[i-1]+s[i]-'0'+1);
        x=min(x,dp_x[i-1]+s[i]-'0');
        dp_d[i]=d; dp_x[i]=x;
        if(i==n-1) dp_d[i]++;
    }
    cout<<min(dp_d[n-1],dp_x[n-1])<<endl;
}