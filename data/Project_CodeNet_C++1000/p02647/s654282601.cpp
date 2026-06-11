#include <bits/stdc++.h>
using namespace std;

int const MAX = 2e5 + 5;
int ar[MAX], n, k, cnt[MAX];
int main(){
    cin >> n >> k;
    for (int i = 1; i <= n; i++){
        cin >> ar[i];
    }
    int bound = 41;
    if (k > bound){
        for (int i = 1; i <= n; i++){
            cout << n << " ";
        }
        cout << "\n";
    } else {
        for (int i =1; i <= k; i++){
            for (int j = 1; j <= n; j++){
                int l = max(1, j - ar[j]);
                int r = min(n, j + ar[j]);
                cnt[l] += 1;
                cnt[r + 1] -= 1;
            }
            for (int j = 1; j <= n; j++){
                cnt[j] += cnt[j - 1];
                ar[j] = cnt[j];
            }
            for (int j = 1; j <= n; j++)
                cnt[j] = 0;
        }
        for (int i = 1; i <= n; i++)
            cout << ar[i] << " ";
        cout << "\n";
    }
}