#include<bits/stdc++.h>
using namespace std;

#define max(a, b) ((a > b) ? a : b)
#define min(a, b) ((a < b) ? a : b)

#define forn(n) for(int i = 0; i < n; i++)
#define fork(k, n) for(int i = k; i < n; i++)

#define pb(n) push_back(n);

typedef long long ll;
typedef double dbl;

const int MX = 1e6;
const int MOD = 1e9 + 7;
const string ALPHA = "abcdefghijklmnopqrstuvwxyz";
const double PI = 3.1415926535;


int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
	//Code here bby
  map<int, vector<int>> locs;
  int grid[3][3];
  for(int r = 0; r < 3; r++){
    for(int c = 0; c < 3; c++){
      int elem;
      cin>>elem;
      grid[r][c] = elem;
      locs[elem].pb((3 * r) + c);
    }
  }
  int n;
  cin>>n;
  while(n--){
    int elem;
    cin>>elem;
    if(locs.count(elem)){
      int pos = locs[elem][locs[elem].size() - 1];
      grid[pos/3][pos%3] *= -1;
      locs[elem].pop_back();
    }
  }
  bool ok = 0;
  for(int r = 0; r < 3; r++){
    if(grid[r][0] < 0 && grid[r][1] < 0 && grid[r][2] < 0){
      ok = 1;
      break;
    }
  }
  for(int c = 0; c < 3; c++){
    if(grid[0][c] < 0 && grid[1][c] < 0 && grid[2][c] < 0){
      ok = 1;
      break;
    }
  }
  if(grid[0][0] < 0 && grid[1][1] < 0 && grid[2][2] < 0){
    ok = 1;
  }
  if(grid[2][0] < 0 && grid[1][1] < 0 && grid[0][2] < 0){
    ok = 1;
  }
  ok ? cout<<"Yes"<<endl : cout<<"No"<<endl;

}
