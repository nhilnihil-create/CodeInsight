#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<long long> L(n);
    for(int i=0;i<n;++i) cin>>L[i];

    sort(L.begin(),L.end());
    long long ans=0;
    for(int i=0;i<n;++i){
        for(int j=i+1;j<n;++j){
            long long rest=L[i]+L[j];
            int n=lower_bound(L.begin(),L.end(),rest)-L.begin();
            ans+=max(n-j-1,0);
        }
    }
    
    cout<<ans<<endl;
}