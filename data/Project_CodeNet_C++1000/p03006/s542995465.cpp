#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int64_t MOD=1000000007;

int main() {
  int N; cin>>N;
  vector<int64_t> A(N);
  vector<int64_t> B(N);
  vector<pair<int64_t,int64_t>> dif;
  vector<int64_t> same;
  rep(i,N) cin>>A.at(i)>>B.at(i);
  if(N==1||N==2) cout<<1;
  else{
  for(int i=0;i<N-1;i++){
    for(int j=i+1;j<N;j++){
      int64_t a=A.at(i),b=A.at(j),c=B.at(i),d=B.at(j);
      dif.push_back(make_pair(a-b,c-d));
    }
  }
  int T=dif.size(), count=0;
  for(int i=0;i<T-1;i++){
    count=0;
    for(int j=i+1;j<T;j++){
      int64_t a=dif.at(i).first,b=dif.at(i).second,c=dif.at(j).first,d=dif.at(j).second;
      if(a==c&&b==d)count++;
      if(a==-1*c&&b==-1*d)count++;
    }
    same.push_back(count);
  }
  sort(same.begin(),same.end());
  reverse(same.begin(),same.end());
  cout<<N-1-same.at(0);
  }
}
