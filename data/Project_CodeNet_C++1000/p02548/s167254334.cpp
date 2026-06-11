#include <bits/stdc++.h>
using namespace std;
int main() { 
    int n,ans=0;
    cin>>n;
    for(int i=1;i<n;i++){
        for(int j=1;i*j<n;j++) ans+=1;
    }
    cout<<ans;
    return 0;
}
