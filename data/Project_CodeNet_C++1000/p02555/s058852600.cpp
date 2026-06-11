#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9 +7;
int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    int * a = new int [n+1];
    int * b = new int [n+1];
    a[0]= a[1]=a[2] =0;
    b[0]=b[1]=b[2]=0;
    for(int i=3;i<=n;i++){
        a[i] = b[i-3]+1;
        b[i] = b[i-1]+a[i];
        a[i]%= mod;
        b[i]%=mod;
    }
    cout<<a[n];
    return 0;
}
