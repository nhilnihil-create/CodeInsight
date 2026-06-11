//      https://www.youtube.com/watch?v=hziG9Nr6KHU

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef long long unsigned llu;
typedef pair<long long, long long> pll;
const long long inf = 2000000000000000000LL;	// 2e18
#define pi                  acos(-1.0)
#define fast                ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define shesh               "\n"
#define ff                  first
#define ss                  second
#define pb                  push_back
#define bp                  pop_back
#define pf                  push_front
#define fp                  pop_front
#define ub                  upper_bound
#define lb                  lower_bound
#define all(x)              x.begin(), x.end()
#define debug(x)            cout<<"debug "<<x<<"\n"
#define mest(a,b)           memset(a,b,sizeof(a))

int main(){
    fast;
    ll t,n,m,i,j,k,l,flag,len,shit,res,ans,temp,q,a,b,d,c;
    cin>>n>>a>>b>>c>>d;
    string s;
    n--,a--,b--,c--,d--;
    cin>>s;
    for(i=b,flag=0;i<d-1&&!flag;i++){
        if(s[i]=='#' && s[i+1]=='#'){
            flag++;
        }
    }
    for(i=a;i<c-1&&!flag;i++){
        if(s[i]=='#' && s[i+1]=='#'){
            flag++;
        }
    }
    if(flag){
        cout<<"No";
        return 0;
    }
    if(c<d){
        cout<<"Yes";
        return 0;
    }
    for(i=b-1,temp=0;i<=d+1;i++){
        if(s[i]!='#'){
            temp++;
        }else temp=0;
        if(temp==3){
            cout<<"Yes";
            return 0;
        }
    }
    cout<<"No";
}
