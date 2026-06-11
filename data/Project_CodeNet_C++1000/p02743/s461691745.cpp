#include <bits/stdc++.h>
using namespace std;
#define ll long long 

long double a,b,c;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>a>>b>>c;
    
    
    long double left = (long double)a+(long double)b+(long double)(2*sqrt(a*b));
    long double right = (long double)c;
    if (left-right>=0.000000000000000000000000000) cout<<"No";
    else cout<<"Yes";
    
    
    




    return 0;
}