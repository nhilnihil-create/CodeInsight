#include <bits/stdc++.h>
#include <math.h>
#define ALL(a)    a.begin(), a.end() 
//#define for(i, K, N)  for(int i = K; i < N; i++)
#define ll long long int
using namespace std;

ll gcd(ll N, ll M){

if(N%M == 0)return M;

else return gcd(M, N%M);

}

ll F(ll N, ll M){
return (N*M)/gcd(N, M);
}

int main() {
ll A, B, C, D;cin >> A >> B >> C >> D;
ll N = B/C - (A - 1)/C + B/D - (A - 1)/D - B/F(C, D) + (A - 1)/F(C, D);
cout << B - A - N + 1;
}