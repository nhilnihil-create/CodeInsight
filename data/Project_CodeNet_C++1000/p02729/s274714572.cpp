#include <bits/stdc++.h>
using namespace std;
 
 
int main() {
    int n,m;
    cin>>n>>m;
    --n,--m;
    int a=0,b=0;
    a=(n*(n+1))/2;//for even
     
    b=(m*(m+1))/2;//for odd
     
    cout<<a+b<<endl;
}