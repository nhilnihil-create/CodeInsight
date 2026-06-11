#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5+5;
int a[N],b[N],n;
int main(){
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<n;i++)cin>>b[i];
    queue<int> q;
    for(int i=0;i<n;i++){
        if(b[i]-a[i]>=b[(i-1+n)%n]+b[(i+1)%n])
            q.push(i);
    }
    ll ans = 0;
    while (!q.empty()){
        int i = q.front();q.pop();
        int k = (b[i]-a[i])/(b[(i+n-1)%n]+b[(i+1)%n]);
        b[i]-=k*(b[(i-1+n)%n]+b[(i+1)%n]);ans+=k;
        i=(i+n-1)%n;
        if(b[i]-a[i]>=b[(i+n-1)%n]+b[(i+1)%n])
            q.push(i);
        i=(i+2)%n;
        if(b[i]-a[i]>=b[(i+n-1)%n]+b[(i+1)%n])
            q.push(i);
    }
    bool f=1;
    for(int i=0;i<n;i++){
        if(a[i]!=b[i]){
            f=0;
            break;
        }
    }
    if(f)cout<<ans<<endl;
    else cout<<-1<<endl;
}