/*

*/
#include<iostream>
#include<iomanip>
#include<ios>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<string>
#include<algorithm>
#include<utility>
#include<math.h>
#include<cstdlib>
#define rep(i, n) for(int i=0;i<n;i++)
#define repb(i, a, b) for(int i=a;i<b;i++)
#define MAX_N 10000

using namespace std;
typedef pair<int, int> P;
typedef long long int ll;

const int INF = 1<<30;
const ll MOD = ll(1e9+7);

int main(){
  vector<vector<int> > bingo(3, vector<int>(3));
  rep(i, 3)rep(j, 3)cin>>bingo[i][j];
  int n;cin>>n;
  vector<int> vec(n);
  rep(i, n)cin>>vec[i];
  bool ans = false;
  rep(i, 3){
    bool tmp = true;
    rep(j, 3){
      if(find(vec.begin(), vec.end(), bingo[i][j])==vec.end())tmp = false;
    }
    if(tmp)ans = true;
    tmp = true;
    rep(j, 3){
      if(find(vec.begin(), vec.end(), bingo[j][i])==vec.end())tmp = false;
    }
    if(tmp)ans = true;
  }
  bool tmp = true;
  rep(i, 3){
    if(find(vec.begin(), vec.end(), bingo[i][i])==vec.end())tmp = false;
  }
  if(tmp)ans = true;
  tmp = true;
  rep(i, 3){
    if(find(vec.begin(), vec.end(), bingo[2-i][i])==vec.end())tmp = false;
  }
  if(tmp)ans = true;
  cout<<(ans?"Yes":"No")<<endl;
  // system("read -n 1 -s -p \"Press any key to continue...\"");
}
