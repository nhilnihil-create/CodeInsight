#include <bits/stdc++.h>
#include <math.h>
#define ALL(a)    a.begin(), a.end() 
//#define for(i, K, N)  for(int i = K; i < N; i++)
#define ll long long int
using namespace std;

int main() {
ll L, R, Ans = 2019;cin >> L >> R;
if(R - L >= 2019){cout << 0;exit(0);}

for(ll i = L; i <= R; i++){
for(ll j = i + 1; j <= R; j++){
Ans = min(Ans, ((i%2019)*(j%2019))%2019);

}
}

cout << Ans%2019;
}