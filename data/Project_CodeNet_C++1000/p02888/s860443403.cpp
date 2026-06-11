#include <bits/stdc++.h>
#include <math.h>
#define ALL(a)    a.begin(), a.end() 
#define rep(i, K, N)  for(long long int i = K; i < N; i++)
#define ll long long int
using namespace std;

int main() {
ll N, Ans = 0;cin >> N;
vector<ll> A(N);


rep(i, 0, N)cin >> A[i];

sort(ALL(A));


rep(i, 0, N){
rep(j, i + 1, N){

ll a = A[i], b = A[j];

if(b - a < A[i])Ans-=2;
if(A[i] <= b - a && b - a < A[j])Ans-=1;

auto Iter1 = upper_bound(ALL(A), A[j] - A[i]);
auto Iter2 = lower_bound(ALL(A), A[i] + A[j]);

Ans += N - (Iter1 - A.begin()) - (A.end() - Iter2);

}
}

cout << Ans/3;

}