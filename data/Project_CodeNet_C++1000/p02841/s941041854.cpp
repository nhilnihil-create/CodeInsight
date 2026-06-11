#include <bits/stdc++.h>
using namespace std;
#include <math.h>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int64_t INF = 1LL << 60;

int main() {
 int m1,d1,m2,d2;
 cin>>m1>>d1>>m2>>d2;
 if(m1<m2){cout<<1<<endl;}
 else if(m1==12&&m2==1){cout<<1<<endl;}
 else{cout<<0<<endl;}
return 0;
} 