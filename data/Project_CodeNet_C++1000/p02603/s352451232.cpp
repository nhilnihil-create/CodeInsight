#include<bits/stdc++.h>
using namespace std;
#define lint long long
#define inf 100000000000000000
#define mod 1000000007
#define MAX 200005
#define pb push_back
#define vit vector<int>::iterator
typedef pair<int,int> pii;

lint A[MAX];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    lint n,ans,ns;
    cin>>n;
    for(lint i=1;i<=n;i++) cin>>A[i];
    ans=1000;
    for(lint i=1;i<n;i++){
        ns=0;
        if(A[i+1]>A[i])
            ns=ans/A[i];
        ans+=(A[i+1]-A[i])*ns;
    }
    cout<<ans;
    return 0;
}
