#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

int main(){
  int n, m;
  while(cin >> n >> m){
    if ((n == 0) && (m == 0)){
      break;
    }
    vector<int> t(n, 0);
    vector<int> h(m, 0);
    int tsum = 0;
    int hsum = 0;
    for (int i = 0; i < n; i++){
      cin >> t[i];
      tsum += t[i];
    }
    for (int i = 0; i < m; i++){
      cin >> h[i];
      hsum += h[i];
    }
    bool found = false;
    int tanswer = 1000000000;
    int hanswer = 1000000000;
    for (int i = 0; i < n; i++){
      for (int j = 0; j < m; j++){
        if ((tsum-hsum) == ((t[i]-h[j])*2)){
          found = true;
          if ((t[i]+h[j]) < (tanswer+hanswer)){
            tanswer = t[i];
            hanswer = h[j];
	  }
	}
      }
    }
    if (found){
      cout << tanswer << ' ' << hanswer << endl;
    }else{
      cout << -1 << endl;
    }
  }
  return 0;
}