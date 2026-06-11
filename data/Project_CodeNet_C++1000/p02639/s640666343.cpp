#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long int arr[5];
    int ans=0;
    for(int i=0;i<5;i++){
        cin>>arr[i];
        if(arr[i]==0){
            ans=i;
        }
    }
    cout<<ans+1;
}
