#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define REP(i,n) for(int i=1;i<=(n);i++)
typedef long long ll;
typedef pair<int,int> pii;

int main(){
    int p,q,r;
    cin>>p>>q>>r;
    int ans=p+q+r;
    ans -=max(p,max(q,r));
    cout<<ans<<endl;
    return 0;
}