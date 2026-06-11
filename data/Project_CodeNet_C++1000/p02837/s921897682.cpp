#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;
typedef long long ll;

int main(){
  int N;
  cin >> N;
  int A[N];
  int b[N];
  vector<vector<int> > x(N),y(N);
  for(int i=0;i<N;i++){
    cin >> A[i];
    b[i] = -1;
    for(int j=0;j<A[i];j++){
      int n,m;
      cin >> n >> m;
      x[i].push_back(n);
      y[i].push_back(m);
    }
  }
  int ans = 0;
  for(ll bit = 0;bit <(1<<N); ++bit){
    int sum = 0;
    for(int i=0;i<N;i++){
      if(bit & (1<<i)){
	b[i]=0;
      }else{
	b[i]=1;
	sum++;
      }
    }
    for(int j=0;j<N;j++){
      for(int t=0;t<A[j];t++){
	if(b[j]==1 && b[x[j][t]-1]!=y[j][t]) {
	  sum = 0;
	  break;
	}
      }
    }
    ans = max(sum,ans);
  }
  cout << ans << endl;
}
