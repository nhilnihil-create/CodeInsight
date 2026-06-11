#include<bits/stdc++.h>
using namespace std;
int main(){
    long long n,i,q;
    cin>>n;
    double a[n],s=0;
    for(i=0;i<n;i++){
        cin>>a[i];
        s=s+(1/a[i]);
    }s=(1/s);
    cout.precision(9);
    cout<<fixed<<s;

return 0;
}
