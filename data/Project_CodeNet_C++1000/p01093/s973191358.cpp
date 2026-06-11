#include <bits/stdc++.h>

using namespace std;

#define INF 1e9

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    while(1){
        int n;
        cin>>n;

        if(n==0)break;

        vector<int> a(n);

        for(int i=0;i<n;i++)cin>>a[i];

        sort(a.begin(),a.end());

        int ans=INF;

        for(int i=0;i<n-1;i++){
            int d=a[i+1]-a[i];
            ans=min(ans,d);
        }

        cout<<ans<<endl;

    }
    
}
