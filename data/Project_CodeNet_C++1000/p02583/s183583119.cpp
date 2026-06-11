#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, ll> Pil;

int N;
ll L[110];

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) cin >> L[i];
    
    int ans = 0;

    for (int i = 0; i < N-2; i++) {
        for (int j = i+1; j < N-1; j++) {
            for (int k = j+1; k < N; k++) {
                if (L[i] + L[j] > L[k] && L[k] + L[j] > L[i] && L[i] + L[k] > L[j]) {
                    if (L[i] != L[j] && L[i] != L[k] && L[k] != L[j]) {
                        ans++;
                    }
                }
            }
        }
    }

    cout << ans << endl;

    return 0;
}
