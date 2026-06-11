#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    //I don't care about anybody, and fuck ratings! I'll go to google!
    int a, b; cin>>a>>b;
    if(a>9 || b>9) return cout<<"-1\n", 0;
    else cout<<a*b<<"\n";
    return 0;
}
