#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void solve(){

    long long x,k,d;
    cin>>x>>k>>d;

    long long p = 0;
    
    if(x<0) x = -1*x;
    
    p = min(k, x/d);
    k -= p;
    
    x -= (p*d);
    
    if(k%2 == 0) cout<<x<<endl;
    else cout<<abs(x-d)<<endl;
return;

}
int main() {
	// your code goes here

        solve();
    
    return 0;
}

