#include<bits/stdc++.h>
using namespace std;
const int M=1e9+7;
long long n,x,y,z,k;
int main()
{
    cin >> n;
    x=y=z=1;
    for(int i=0; i<n; i++) x*=10,x%=M;
    for(int i=0; i<n; i++) y*=9,y%=M;
    for(int i=0; i<n; i++) z*=8,z%=M;
    k = (x-2*y+z)%M;
    if(k<0) k+=M;
    cout << k;
    return 0;
}