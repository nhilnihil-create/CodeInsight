#include <bits/stdc++.h>
using namespace std;
#include <math.h>
#include <cmath>
#include <iomanip>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int mod=1e9+7;

int main() {
 map<int,int>k;
 int N;
 cin>>N;
 for(int i=0;i<N-1;i++){
   int a;
   cin>>a;
   k[a]++;
 }
for(int i=1;i<=N;i++){
  cout<<k[i]<<endl;
}
 return 0;  
}