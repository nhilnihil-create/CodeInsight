#include<iostream>
using namespace std;

bool canMakeTriangle(int a, int b, int c) {
    bool ans = false;
    if (a + b > c && a - b < c && b - a < c) {
        ans = true;
    } else if (b + c > a && b - c < a && c - b < a) {
        ans = true;
    } else if (a + c > b && a - c < b && c - a < b){
        ans = true;
    }
    return ans;
}

int main() {
    int N; cin >> N;
    int L[N];
    for (int i = 0; i < N; i++) {
        cin >> L[i];
    }
    int ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            for (int k = j + 1; k < N; k++) {
                if (canMakeTriangle(L[i], L[j], L[k]) && L[i] != L[j] && L[j] != L[k] && L[i] != L[k]) {
                    ans++;
                }
            }
        }
    }
    cout << ans << endl;
}

