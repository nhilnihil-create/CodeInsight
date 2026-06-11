#include <bits/stdc++.h>
using namespace std;
#include <math.h>
#include <iomanip>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const int mod=1000000007;
const int INF=1001001001;

int main() {
  int N;
  cin>>N;
  vector<pair<int,int>>p(N);
  vector<int>num(N);
  for(int i=0;i<N;i++){
    int x,y;
    cin>>x>>y;
    p[i]=make_pair(y,x);
    num[i]=i;
  }
  sort(p.begin(),p.end());
  int cnt=0;
  double sum=0;
  do{
    for(int i=0;i<N;i++){
      if(i>0){
        double dx=(p[num[i]].second-p[num[i-1]].second);
        double dy=(p[num[i]].first-p[num[i-1]].first);
        sum+=sqrt(dx*dx+dy*dy);
      }
    }
    cnt++;
  }while(next_permutation(num.begin(),num.end()));
  cout<<fixed<<setprecision(10)<<sum/cnt<<endl;
  return 0;  
}