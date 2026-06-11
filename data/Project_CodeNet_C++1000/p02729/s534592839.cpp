#include <bits/stdc++.h>
using namespace std;
int main(void){
    int n,m,a,b;
    cin>>n>>m;
    
    a = n*(n-1);
    b = m*(m-1);
    cout<<(a+b)/2<<"\n";
    return 0;
}