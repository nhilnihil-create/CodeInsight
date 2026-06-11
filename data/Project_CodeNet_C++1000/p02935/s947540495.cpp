#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    float arr[n];
    for (int i=0;i<n;++i){
        cin>>arr[i];
    }
    sort(arr,arr+n);
    float ans = (arr[0]+arr[1])/2;
    for (int i=2;i<n;++i){
        ans = (ans+arr[i])/2;
    }
    cout<<ans;
}