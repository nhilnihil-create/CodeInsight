#include<bits/stdc++.h>
using namespace std;
typedef long long int INT;
int n,k;
int main()
{
    cin>>n>>k;
    INT ans=0;
    vector<int> h(n);
    for (int i=0;i<n;++i){
        cin>>h.at(i);
    }
    if(n<=k){
        ans=0;
    }
    else{
        sort(h.begin(),h.end(),greater<int>());
        for (int i=0;i<k;i++){
            h.at(i)=0;
        }
        for (int i=0;i<n;i++){
            ans+=h.at(i);
        }
    }
    cout<<ans<<endl;
}