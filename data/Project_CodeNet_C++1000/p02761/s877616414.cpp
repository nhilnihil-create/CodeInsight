#include <bits/stdc++.h>
using namespace std;
#include <math.h>
#include <iomanip>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int INF=1001001001;
vector<pair<int64_t,int64_t>>prime_factorize(int64_t x){
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
  int N,M;
  cin>>N>>M;
  vector<int>s(M),c(M);
  for(int i=0;i<M;i++){
    cin>>s[i]>>c[i];
    s[i]--;
  }
  vector<int>t(N);
  if(N>1){t[0]=1;}
  vector<bool>use(N,false);
  for(int i=0;i<M;i++){
    if(N>1&&s[i]==0&&c[i]==0){cout<<-1<<endl;return 0;}
    if(use[s[i]]&&t[s[i]]!=c[i]){cout<<-1<<endl;return 0;}
    t[s[i]]=c[i];
    use[s[i]]=true;
  }
  for(int i=0;i<N;i++){
    cout<<t[i];
  }cout<<endl;

  return 0;
}