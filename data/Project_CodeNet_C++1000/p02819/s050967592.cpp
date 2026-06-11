#include <bits/stdc++.h>
using namespace std;


typedef long long ll;
typedef pair<int, int> P;

struct edge {int to; ll cost; };

int dx[] = {-1, 1, 0,  0};
int dy[] = { 0, 0, 1, -1};
 
int main(){
  vector<bool> isp(1000000, true);
  isp[0] = false;
  isp[1] = false;
  for(int i=2; i<1000000; i++){
    if(isp[i]){
      for(int j=2; i*j<1000000; j++){
        isp[i*j] = false;
      }
    }
  }
  int x;
  cin >> x;
  for(int i=x; i<1000000; i++){
    if(isp[i]){
      cout << i << endl;
      return 0;
    }
  }
  return 0;
}
