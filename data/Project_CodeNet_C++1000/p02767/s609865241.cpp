#include<bits/stdc++.h>
 using namespace std;
 #define rep(i, c) for(int i = 0; i < (int)c; i++)
 const int inf = 1000000000; // 10^9

 int main() {
 int N;
 cin >> N;
 vector<int> X(N);
 rep(i, N) cin >> X[i];
 int ans = inf;
 for(int i = 1; i <= 100; i++) { // L やR の計算が不要
     int cost = 0;
 rep(j, N) cost += (X[j] - i) * (X[j] - i);
 ans = min(ans, cost);
 }
 cout << ans << endl;
 return 0; }
