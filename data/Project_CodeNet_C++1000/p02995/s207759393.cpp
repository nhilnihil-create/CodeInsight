#include <bits/stdc++.h>
using namespace std;
#include <math.h>
#include <iomanip>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int INF=1001001001;
vector<pair<int64_t,int64_t>>pppp(int64_t x){
  vector<pair<int64_t,int64_t>>p;
  for(int64_t i=2;i*i<=x;i++){
    int cnt=0;
    if(x%i==0){
    while(x%i==0){cnt++;x/=i;}
    p.push_back(make_pair(i,cnt));
    }
  }
  if(x!=1){p.push_back(make_pair(x,1));}
  return p; 
}
 
int main() {
 int64_t A,B,C,D;
 cin>>A>>B>>C>>D;
 int64_t c=(B-A+1)-(B/C-(A-1)/C);
 int64_t d=(B-A+1)-(B/D-(A-1)/D);
 int64_t k=C*D/__gcd(C,D);
 int64_t cd=(B-A+1)-(B/k-(A-1)/k);
 cout<<c+d-cd<<endl;
 return 0;
}