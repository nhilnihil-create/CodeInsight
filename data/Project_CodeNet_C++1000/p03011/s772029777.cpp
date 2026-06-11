#include <bits/stdc++.h>

#define FOR(i,a,b) for(ll i=a;i<ll(b);i++)
#define REP(i,n) FOR(i,0,n)

#define MOD 10e9+7

using namespace std;

int main(){
int P,Q,R;
cin >> P >> Q >> R;
cout << (P < Q ? (Q < R ? P + Q : P + R):(P < R ? P + Q : Q + R))<< endl;
return 0;
}
