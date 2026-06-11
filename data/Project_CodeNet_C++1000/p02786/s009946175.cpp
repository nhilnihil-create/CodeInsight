#include<bits/stdc++.h>
using namespace std;

int main() {
    long long H;
    cin >> H;
    long long i=0;
    long long ans=0;
    while (H>=1) {
        ans += pow(2,i);
        H/=2;
        i++;
    }
    cout << ans << endl;
}