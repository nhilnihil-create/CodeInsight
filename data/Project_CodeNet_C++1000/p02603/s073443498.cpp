#include <bits/stdc++.h>
using namespace std;
long long N, A[87], CurrentMoney = 1000;
 int main() {
 cin >> N;
 for (int i = 1; i <= N; i++) cin >> A[i];
 for (int i = 1; i <= N - 1; i++) {
 long long Stocks = 0;
 if (A[i] < A[i + 1]) Stocks = CurrentMoney / A[i];
 CurrentMoney += (A[i + 1] - A[i]) * Stocks;
 }
 cout << CurrentMoney << endl;
}
