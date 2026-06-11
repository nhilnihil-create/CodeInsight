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
    int x,n;
    cin>>x>>n;
    map<int,int>m;
    REP(i,n){
        int a;
        cin>>a;
        m[a]++;
    }
    int ans=0;
    for(int i=0;;i++){
        if(m[x-i]==0){
            ans=x-i;
            break;
        }
        if(m[x+i]==0){
            ans=x+i;
            break;
        }
    }
    OUT(ans);
    return 0;
}
