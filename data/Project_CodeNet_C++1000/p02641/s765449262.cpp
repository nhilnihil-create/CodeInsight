#include <bits/stdc++.h>
using namespace std;

int a, X, N, res, mindif;
int arr[105];

int main() {
    
    ios_base::sync_with_stdio(false);
    cin >> X >> N;
    res = 200;
    mindif = 200;
    if(N == 0) cout << X;
    else {
        for(int i = 0; i < N; i++) {
            cin >> a;
            arr[a]++;
        }
        for(int i = 0; i <= 101; i++) {
            if(arr[i] == 0) {
                if(abs(X - i) < mindif) {
                    res = i;
                    mindif = abs(X - i);
                }
                else if(abs(X - i) == mindif) {
                    res = min(res, i);
                }
            }
        }
        cout << res;
    }
}