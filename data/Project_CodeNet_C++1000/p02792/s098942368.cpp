#include <bits/stdc++.h>
using namespace std;
#include <math.h>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int64_t INF = 1LL << 60;

pair<int,int> func(int x){
  int a=x%10;
  int b;
  while(x>0){
    b=x%10;
    x/=10;
  }
  return pair<int,int>(a,b);
}

int main() {
 int N;
 cin>>N;
 map<pair<int,int>,int>k;
 for(int A=1;A<=N;A++){
   k[func(A)]++;
 }
int ans=0;
 for(int B=1;B<=N;B++){
   pair<int,int>t=func(B);
  ans+= k[pair<int,int>(t.second,t.first)];
 }
 cout<<ans<<endl;
return 0;
} 