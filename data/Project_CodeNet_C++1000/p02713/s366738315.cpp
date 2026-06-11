#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i< (n); i++)
using namespace std;
using ll = long long;
typedef pair<int,int> P;

int main() {
    int K; cin >> K;
    int sum = 0;
    for(int a=1; a<=K; a++) {
        for(int b=1; b<=K; b++) {
            for(int c=1; c<=K; c++) {
                sum += gcd(gcd(a,b),c);
            }
        }
    }
    cout << sum << endl;
    return 0;
}