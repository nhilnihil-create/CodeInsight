#include <bits/stdc++.h>
using namespace std;
#define lli long long int
int main() {
    lli a,b,c,d;
    cin>>a>>b>>c>>d;
    
    lli o = a*c; 
    o = max(o,a*d);
    o =max(o,b*d);
    o = max(o,b*c);
    cout<<o<<endl;

}
