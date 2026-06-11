#include <bits/stdc++.h>
#include <math.h>
#define ALL(a)    a.begin(), a.end() 
#define rep(i, K, N)  for(long long int i = K; i < N; i++)
#define ll long long int
using namespace std;

int main() {
ll N, M;cin >> N >> M;
vector<ll> A(M);
vector<ll> B(N + 1);

rep(i, 0, M)cin >> A[i];

B[0] = 1;ll a = 0;
if(M == 0)A.push_back(-1);
rep(i, 1, N + 1){
if(i == A[a]){B[i] = 0;a++;}
else{
if(i == 1)B[i] = 1;
else B[i] = (B[i - 1]%1000000007 + B[i - 2]%1000000007)%1000000007;
}

}

cout << B[N];
}