#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int N=2e5+5;
int ar[N],br[N];
int main() {
    int n;
    cin>>n;
    for(int i=1; i<=n; ++i) {
        cin>>ar[i]>>br[i];
    }
    sort(ar+1,ar+n+1);
    sort(br+1,br+n+1);
    if(n%2) {
        int x=(n+1)/2,y=(n+1)/2;
        cout<<br[y]-ar[x]+1<<endl;
    } else {
        int x=n/2,y=(n/2)+1,ans;

        if(ar[x]+br[y]>=ar[y]+br[x]) {
            ans=br[y]-ar[y]+1;
            ans+=(br[x]+br[y])-(ar[x]+br[y]+1)+1;
        } else {
            ll d=min(br[y]-ar[y]+1,br[x]-ar[x]+1);
            ans=d+max(br[y]-ar[y],br[x]-ar[x]);
        }
        cout<<ans<<endl;
    }
    return 0;
}
