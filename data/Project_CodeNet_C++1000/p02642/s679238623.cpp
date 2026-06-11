#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define N 2005
#define INF 1000000005
#define INFLL (long long)1e18
#define PI 3.1415926535897
typedef long long ll;
#define ALL(v) (v).begin(),(v).end()
#define SZ(x) int(x.size())
#define IN(a) cin>>(a)
#define OUT(a) cout<<(a)<<endl
typedef pair<int,int> P;
const int MAX = 1000005;
const int MOD = 1000000007;
int main(){
    int n;
    cin>>n;
    vector<int>a(n);
    REP(i,n)cin>>a[i];
    vector<bool>check(MAX+1,true);
    sort(ALL(a));
    int ans=0;
    REP(i,n){
        if(check[a[i]]){
            if(i<n-1&&a[i]!=a[i+1])ans++;
            if(i==n-1)ans++;
            for(int j=1;a[i]*j<=MAX;j++){
                check[a[i]*j]=false;
            }
        }
    }
    OUT(ans);
    return 0;
}
