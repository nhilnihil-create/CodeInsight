#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define rep2(i,x,n) for(int i=x; i<(n); i++)
#define ALL(n) begin(n),end(n)
#define INF ((1<<30)-1)
#define LINF (1LL<<60)
#define EPS (1e-10)
typedef long long Int;
typedef pair<Int, Int> P;
typedef pair<int, int> pint;
struct cww{cww(){ios::sync_with_stdio(false);cin.tie(0);}}star;
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    Int k ;cin>>k;
    int ans=-1;
    vector<Int> a(k+1,0);
    a[0]=0;
    for(int i=0 ;i<k; i++){
        a[i+1]=(10*a[i]+7)%k;
        if(a[i+1]<0) a[i+1]+=k;
        if(a[i+1]==0) {ans=i+1;
        break;
        }
    }
    cout<<ans<<endl;
    return 0;
}