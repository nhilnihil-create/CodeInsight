#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout<<setprecision(12);
    //I don't care about anybody, and fuck ratings! I'll go to google!
    int n; cin>>n;
    if(n&1^1) return cout<<"0.5\n", 0;
    double x = (n+1)/2.0;
    x /= n;
    cout<<x<<"\n";
    return 0;
}
