#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int ans=1000*(n/500);
    int x=n%500;
    ans+=5*(x/5);
    cout<<ans;
}