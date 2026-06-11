#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie();
    int x;
    cin>>x;
    int a = x/500;
    x = x%500;
    int b = x/5;
    long long ans = a*1000;
    ans += b*5;
    cout<<ans;
    return 0;
}