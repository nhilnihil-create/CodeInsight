#include <bits/stdc++.h>
#define rep(i,j,k) for(int i=(int)j;i<(int)k;i++)
#define itrep(x) for(auto it=(x).begin();it!=(x).end();it++) 
#define Sort(x) sort((x).begin(),(x).end())
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define vi vector<int>
#define INF (int)1e9
#define INFL 1e18
#define MOD 1000000007
#define pb push_back
#define MP make_pair
#define PI 3.1415926535
typedef long long int ll;
typedef std::pair<int,int> P;
int D=1;
int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
 
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> x(n),y(n);
    rep(i,0,n)cin>>x[i];
    rep(i,0,n)cin>>y[i];
    
    rep(i,1,4){
        double ans=0;
        rep(j,0,n){
            ans+=pow(abs(x[j]-y[j]),i);
        }
        printf("%.10f\n",pow(ans,1.0/i));
    }
    
    int ans=0;
    rep(i,0,n){
        ans=max(ans,abs(x[i]-y[i]));
    }
    printf("%.10f\n",(double)ans);
    return 0;
}
