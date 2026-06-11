#include <bits/stdc++.h>
using namespace std;
using pll=pair<long long,long long>;
const long double pi=atan2l(0,-1);

int N;

pair<long long,long long> operator+(pair<long long,long long> &a,pair<long long,long long> &b) {
  return make_pair(a.first+b.first,a.second+b.second);
}

int main() {
  cin >> N;
  vector<pll> A(N);
  for (int i=0;i<N;i++) {
    cin >> A[i].first >> A[i].second;
  }
  vector<pair<long double,int>> arg(2*N);
  for (int i=0;i<N;i++) {
    arg[i]=make_pair(atan2(A[i].second,A[i].first),i);
    arg[i+N]=make_pair(atan2(A[i].second,A[i].first)+2*pi,i);
  }
  sort(arg.begin(),arg.end());
  long double ans=0;
  for (int i=0;i<N;i++) {
    int j=i;pair<long long,long long> X=make_pair(A[arg[i].second].first,A[arg[i].second].second);
    while (((X.first+A[arg[j+1].second].first)*A[arg[j+1].second].first+(X.second+A[arg[j+1].second].second)*A[arg[j+1].second].second>=
            -1*X.first*A[arg[j+1].second].first-X.second*A[arg[j+1].second].second && arg[j+1].first-atan2(X.second,X.first)<pi)
           || X.first*A[arg[j+1].second].first+X.second*A[arg[j+1].second].second>=0 && j+1<i+N) {
      j++;
      X=X+A[arg[j].second];
    }
    long long x=0LL,y=0LL;
    for (int k=i;k<=j;k++) {
      x+=A[arg[k].second].first;
      y+=A[arg[k].second].second;
    }
    long double d=sqrt(x*x+y*y);
    ans=max(ans,d);
  }
  cout << setprecision(20) << ans << endl;
}