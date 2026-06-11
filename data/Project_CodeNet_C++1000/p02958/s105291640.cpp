#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,ans=0;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<n;i++){
        if(a[i]!=i+1)ans++;
    }
    if(ans==2||ans==0)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}