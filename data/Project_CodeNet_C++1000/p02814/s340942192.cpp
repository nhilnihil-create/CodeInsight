#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n,m;
    cin >> n >> m;
    long long a[100005];
    //int b[100005];
    for(int i=0; i<n; i++) cin >> a[i];
    long long p=1;
    for(int i=0; i<n; i++){
        long long x=1;
        while(a[i]%2==0){
            a[i] /= 2;
            x *= 2;
        }
        if(i==0){
            p=x;
        } else if(p != x){
            cout << 0 << endl;
            return 0;
        }
    }

    p /= 2;
    long long s=1;
    for(int i=0; i<n; i++){
        s = s/__gcd(s,a[i])*a[i];
        if(s*p>m){
            cout << 0 << endl;
            return 0;
        }
    }

    cout << (m+s*p)/(2*s*p) << endl;
}