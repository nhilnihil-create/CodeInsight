#include <bits/stdc++.h>
#include <math.h>
#define ALL(a)    a.begin(), a.end() 
#define for(i, K, N)  for(int i = K; i < N; i++)
#define ll long long int
using namespace std;

int main() {
ll N, K;cin >> N >> K;
long double Ans = 0, sum = 0;
vector<long double> V(N);
for(i, 0, N){
cin >> V[i];
if(i < K)sum += (V[i] + 1)/2;
}
Ans = sum;
for(i, 0, N - K){
sum += (V[K + i] + 1)/2 - (V[i] + 1)/2;
Ans = max(Ans, sum);
}
cout << fixed << setprecision(10) << Ans;
}