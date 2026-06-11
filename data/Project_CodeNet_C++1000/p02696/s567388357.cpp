#include <bits/stdc++.h>
#include <math.h>
#define ALL(a)    a.begin(), a.end() 
#define rep(i, K, N)  for(long long int i = K; i < N; i++)
#define ll long long int
using namespace std;

int main() {
double N, A, B;cin >>  A >> B >> N;

if(N < B){cout << floor(A*N/B) - A*floor(N/B);exit(0);}
   

cout << floor(A*(B - 1)/B) - A*floor((B - 1)/B);

}