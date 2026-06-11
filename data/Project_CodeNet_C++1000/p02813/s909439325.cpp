#include <bits/stdc++.h>
using namespace std;
int n,p1,a,b,vis[9];
int factorial(int x) {
    int ret=1;
    for (int i=1; i<=x; i++) ret*=i;
    return ret;
}
int main() {
    cin>>n;
    for (int i=n; i>=1; i--) {
        cin>>p1;
        int cnt=0;
        vis[p1]=1;
        for (int j=1; j<=p1; j++) {
            if (!vis[j]) cnt++;
        }
        a+=(cnt*factorial(i-1));
    }
    memset(vis,0,sizeof(vis));
    for (int i=n; i>=1; i--) {
        cin>>p1;
        vis[p1]=1;
        int cnt=0;
        for (int j=1; j<=p1; j++) {
            if (!vis[j]) cnt++;
        }
        b+=(cnt*factorial(i-1));
    }
    cout<<abs(a-b)<<'\n';
}