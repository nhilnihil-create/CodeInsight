#include<bits/stdc++.h>
using namespace std;

int main()
{
  int N, M, P;
  while( cin >> N >> M >> P, N + M + P ) {
    int X[100];
    int sum = 0;
    for(int i=0; i<N; i++) cin >> X[i], sum += X[i] * 100;
    sum *= (100 - P);
    if( X[M-1] == 0 ) cout << 0 << endl;
    else cout << sum / X[M-1] / 100 << endl;
  }
}