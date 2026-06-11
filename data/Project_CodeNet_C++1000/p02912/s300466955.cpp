#include <bits/stdc++.h>
using namespace std;
#define int long long
//#define ll long long
const int maxm=3e5+5;
int a[maxm];
int n,m;
signed main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    priority_queue<int,vector<int>,less<int> >q;
    for(int i=1;i<=n;i++){
        q.push(a[i]);
    }
    while(m&&!q.empty()){
        int x=q.top();q.pop();
        x/=2;
        m--;
        if(x)q.push(x);
    }
    int ans=0;
    while(!q.empty()){
        ans+=q.top();q.pop();
    }
    cout<<ans<<endl;
    return 0;
}
/*


*/
