#include<bits/stdc++.h>
using namespace std;
int main() {
    int n,k;
    cin>>n>>k;
    vector<int> p(n),c(n);
    for(int i=0;i<n;i++) {
        cin>>p[i];
        p[i]--;
    }
    for(int i=0;i<n;i++) {
        cin>>c[i];
    }
    long long ans=-1e18;
    for(int i=0;i<n;i++) {
        int v=i;
        long long cs=0;
        int cc=0;
        while(1) {
            cc++;
            cs+=c[v];
            v=p[v];
            if (v==i) {
                break;
            }
        }
        long long path=0;
        int cnt=0;
        while(1) {
            cnt++;
            path+=c[v];
            if (cnt>k) {
                break;
            }
            int num=(k-cnt)/cc;
            long long sce=path+max(0ll,cs)*num;
            ans=max(ans,sce);
            v=p[v];
            if(v==i) {
                break;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}