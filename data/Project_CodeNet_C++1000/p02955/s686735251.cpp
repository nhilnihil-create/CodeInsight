#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int N, K;
int arr[505];
int rem[505];
vector <int> factors;

void findFactors(int tot){
    int p = (int) sqrt(tot)+1;
    for (int i=1; i<=p; i++) {
        if (tot % i == 0) {
            factors.push_back(i);
            factors.push_back(tot/i);
        }
    }
    sort(factors.begin(), factors.end(), greater<>());
}

int main() {
    cin >> N >> K;
    int tot = 0;
    for (int i=1; i<=N; i++){
        scanf("%d", &arr[i]);
        tot += arr[i];
    }
    findFactors(tot);
    int ans;
    for (int f: factors){
        for (int i=1; i<=N; i++){
            rem[i] = arr[i] % f;
        }
        sort(rem+1, rem+N+1);
        int sum = 0, req1 = 0, req2 = 0;
        int l = 0, r = N;
        while (l <= r){
            if (sum <= 0) {
                sum += rem[l];
                req1 += rem[l];
                l++;
            } else {
                sum -= (f-rem[r]);
                req2 += (f-rem[r]);
                r--;
            }
        }
        if (req1 <= K && req2 <= K) {
            ans = f;
            break;
        }
    }
    cout << ans << endl;
    return 0;
}