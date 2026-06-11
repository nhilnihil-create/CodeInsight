#include<bits/stdc++.h>

using namespace std;

int main(){
    int k, n;
    cin>>k>>n;
    vector<int>v(n), v1(n);
    for(int i=0;i<n;++i)cin>>v[i];
    for(int i=0;i<n-1;++i)v1[i]=v[i+1]-v[i];
    v1[n-1]=v[0]+k-v[n-1];
    sort(v1.begin(),v1.end());
    cout<<k-v1[n-1];

    return 0;

}
