#include<bits/stdc++.h>
using namespace std;
int main(){
    int a[5];
    int ans;
    for(int i=0;i<5;i++) {
        cin>>a[i];
        if(a[i]==0) ans = i+1;
    }
    cout<<ans<<endl;
    return 0;
}