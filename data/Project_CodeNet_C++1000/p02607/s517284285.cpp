#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,ans=0;
    cin>>n;
    int arr[n+1];
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        if(i%2==1 && arr[i]%2==1)
            ans++;
    }
    cout<<ans<<endl;
}
