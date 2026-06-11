#include <bits/stdc++.h>
#include <math.h>
#define ALL(a)    a.begin(), a.end() 
//#define for(i, K, N)  for(int i = K; i < N; i++)
#define ll long long int
using namespace std;

int main() {
long double W, H, x, y;cin >> W >> H >> x >> y;

cout << fixed << setprecision(9) << (W*H)/2 << " ";

if(W - 2*x == 0 && H - 2*y == 0){cout << 1;exit(0);}
else cout << 0;
}