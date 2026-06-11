#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
  ll K,N,i;
  ll A[222222];
  cin >> K >> N;
  for(i=0;i<=N-1;i++)
    cin >> A[i];
  ll B[222222];
  for(i=0;i<=N-2;i++)
    B[i] = A[i+1] - A[i];
  B[N-1] = K - (A[N-1] - A[0]);
  ll max = 0;
  for(i=0;i<=N-1;i++)
    if(B[i] > max) max = B[i];
  cout << K - max << endl;
}

