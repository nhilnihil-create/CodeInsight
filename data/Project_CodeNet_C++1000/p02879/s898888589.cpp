#include <bits/stdc++.h>
using namespace std;
#include <math.h>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int64_t INF = 1LL << 60;

int main() {
 int A,B;
 cin>>A>>B;
 if(A<=9&&A>=1&&B<=9&&B>=1){cout<<A*B<<endl;}
 else{cout<<-1<<endl;}
 
 return 0;
}
