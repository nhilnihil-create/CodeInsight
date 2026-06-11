#include <bits/stdc++.h>
using namespace std;
#include <math.h>
#include <iomanip>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int INF=1001001001;

int main() {
  int N,M;
  cin>>N>>M;
  vector<int>ans(N);
  vector<bool>used(N,false);
  if(N>1){ans[0]=1;}
  for(int i=0;i<M;i++){
    int s,c;
    cin>>s>>c;
    s--;
    if(N>1&&s==0&&c==0){cout<<-1<<endl;return 0;}
    if(used[s]&&ans[s]!=c){cout<<-1<<endl;return 0;}
    used[s]=true;
    ans[s]=c;
  }
  for(int i=0;i<N;i++){
    cout<<ans[i];
  }cout<<endl;
  return 0;  
}