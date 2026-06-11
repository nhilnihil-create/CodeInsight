#include <iostream>
#include <vector>
#include <cmath>
#include <string>
using namespace std;
int main() {
    long long n,t;
    long long a1=0;
    cin >> n;
    long long b[n];
    long long ans[n];

    for(long long i=0;i<n;i++){
        cin >> t;
        b[i] = t*2;
        if(i%2==0) a1 += t;
        else a1 -= t;
    }

    ans[0] = a1;
    cout << a1 << " ";
    for(long long i=0;i<n-1;i++) {
        long long p=b[i] - ans[i];
        ans[i+1] = p;
        cout << p;
        if(i==n-2) cout << endl;
        else cout << " ";
    }
}