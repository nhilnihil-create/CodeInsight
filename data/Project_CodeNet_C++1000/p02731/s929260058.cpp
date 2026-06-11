#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
int main(void){
    int l;
    double ans;
    cin>>l;
    
    ans = pow(l,3)/27;
    
    cout<<fixed<<setprecision(12)<<ans<<"\n";

    return 0;
}