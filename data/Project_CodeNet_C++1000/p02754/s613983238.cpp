#include<bits/stdc++.h> 
using namespace std;
using ll = long long;

#define fast_io ios_base::sync_with_stdio(false) ; cin.tie(0); cout.tie(0);

int main() {
    fast_io;
    long long n,a,b,m,s,k;
    cin>>n>>a>>b;
    m=a+b;
    s=n%m;
    k=n/m;
    
    if(s>a) {
        s=a;
    }
    cout<<(k*a)+s<<endl;
}

