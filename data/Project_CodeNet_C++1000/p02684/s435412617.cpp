#include <bits/stdc++.h>
using namespace std;
#include <math.h>
#include <iomanip>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const int mod=1000000007;
const int INF=1001001001;

int main() {
  int64_t N,K;
  cin>>N>>K;
  vector<int>A(N);
  for(int i=0;i<N;i++){
    cin>>A[i];
    A[i]--;
  }
  deque<int>root;
  vector<bool>use(N,true);
  int r=0,END=0;
  for(int i=0;i<N;i++){
    if(!use[r]){
      while(root[0]!=r){
        K--;
        root.pop_front();
        if(K==0){
          cout<<root[0]+1<<endl;return 0;
        }
      }
      break;
    }
    root.push_back(r);
    use[r]=false;
    r=A[r];  
  }
  cout<<root[K%root.size()]+1<<endl;
  return 0;  
}