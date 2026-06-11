#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int ans = (n/1000+1)*1000-n;
    if(ans==1000) ans =0;
    cout<<ans<<endl;
    return 0;
}