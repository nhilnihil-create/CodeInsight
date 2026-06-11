#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int main(){
    int n;
    cin>>n;
    int a[n+1];
    int ans=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(i%2!=0&&a[i]%2!=0)ans++;
    }
    cout<<ans<<endl;
    return 0;
}