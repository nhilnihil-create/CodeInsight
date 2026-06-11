#include <bits/stdc++.h>
using namespace std;

int main(){
    int x;
    cin>>x;
    int ans=1;
    int now=x;
    while(now%360!=0){
        ans++;
        now+=x;
    }
    cout<<ans<<endl;
}