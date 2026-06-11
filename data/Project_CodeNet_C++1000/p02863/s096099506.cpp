#include <iostream>
#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
int n,m,menu[3002],a,b,c,ans;
vector<P> v;
int main(void){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a>>b;
        v.push_back({a,b});
    }
    sort(v.begin(),v.end());
    for(int i=0;i<n;i++){
        for(int j=m-1;j>=0;j--){
            if(menu[j]!=0||j==0){
                int L=min(m+1,j+v[i].first);
                menu[L]=max(menu[L],menu[j]+v[i].second);
            }
        }
    }
    for(int i=0;i<=m+1;i++)ans=max(ans,menu[i]);
    cout<<ans<<endl;
}
