#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<string>
#include<sstream>
#include<cmath>
#include<numeric>
#include<map>
#include<stack>
#include<queue>
#include<cassert>
using namespace std;
int inf = 1000000000;

int main(void) {
  int w, h;

  vector< vector<int> > ans;
  for(int i=1; i<=150; i++){
    for(int j=i+1; j<=150; j++){
      vector<int> tmp(3);
      tmp[0] = i*i+j*j;
      tmp[1] = i;
      tmp[2] = j;
      ans.push_back(tmp);
    }
  }
  sort(ans.begin(), ans.end());


  while( cin >> h >> w ){
    if( w == 0 && h == 0 ) break;
    int t = w*w + h*h;
    for(int i=0; i<ans.size(); i++){
      if( ans[i][0] < t ) continue;
      if( ans[i][0] == t && ans[i][1] <= h ) continue;

      cout << ans[i][1] << " " << ans[i][2] << endl;
      break;
    }

  }


  return 0;
}


// EOF