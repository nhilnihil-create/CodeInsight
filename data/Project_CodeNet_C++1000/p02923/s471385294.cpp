#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int ans = 0,m = 0;
    int arr[n];
    for (int i=0;i<n;++i){
        cin>>arr[i];
    }
    int temp = arr[0];
    for(int i=1;i<n;++i){
        if (arr[i]<=temp){
            m++;
            temp = arr[i];
        }
        else{
            ans = max(ans,m);
            temp = arr[i];
            m=0;
        }
    }
    ans = max(ans,m);
    cout<<ans;
    
}