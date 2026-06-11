#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);
    int n,x,y; cin>>n>>x>>y;
    vector<int>ans(n);
    for(int i=1;i<n;i++) {
        for(int j=i+1;j<=n;j++) {
            int min_dist=min(abs(i-j),abs(x-i)+abs(y-j)+1);
            ans[min_dist]++;
        }
    }
    for(int i=1;i<n;i++) {
        cout<<ans[i]<<endl;
    }
}