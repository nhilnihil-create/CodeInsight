#include <bits/stdc++.h>          
using namespace std;       
typedef long long ll;        

int main() {
    ll N;
    int K;
    cin >> N >> K;
    ll count = 1;
    while (N>=K) {
        N /= K;
        count++;
    }
    cout << count << endl;
}