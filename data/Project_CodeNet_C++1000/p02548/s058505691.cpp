#include<bits/stdc++.h>
using namespace std;
int a[100][2];
int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    int n,ans=0;
    cin>>n;
    for(int i=1; i<n;i++){
        ans+=(n-1)/i;
    }
    cout<<ans<<endl;
    return 0;
}