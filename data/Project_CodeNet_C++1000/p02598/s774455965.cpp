#include <bits/stdc++.h>

using namespace std;
vector<int>v;
int n,k;
bool chk(int mn){
    int tmk=0;
    for(int i=0;i<n;i++){
        tmk+=v[i]/mn+!!(v[i]%mn)-1;
    }

    return tmk<=k;
}
int main()
{///{}
    cin>>n>>k;
    v.resize(n);
    for(int i=0;i<n;i++)
        cin>>v[i];

    int l=1,r=1e9+5;
    int ans;
    while(l<=r){
        int mid=l+(r-l)/2;
        if(chk(mid)){
            r=mid-1;
            ans=mid;
        }else{
            l=mid+1;
        }

    }

    cout<<ans<<'\n';

    return 0;
}
