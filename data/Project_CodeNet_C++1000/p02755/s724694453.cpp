#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const long long INF = 1LL << 60;

int main(){
    int A, B;
    cin >> A >> B;
    for(int i=1; i<(B+1)*10; i++) {
        int a = floor(i * 0.08);
        int b = floor(i * 0.10);
        if(a == A && b == B) {
            cout << i << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}

