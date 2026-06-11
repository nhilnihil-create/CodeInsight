#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <string>
#include <cmath>

using ll = long long;
using namespace std;


int main() {
	int n;
  	cin >> n;
  	int v[n];
  	for(int i=0;i<n;i++) cin >> v[i];
  
  	int b4 = v[0];
  	int ans = 0;
  	
  	int t = 0;
  	for(int i=1;i<n;i++) {
    	if(b4 >= v[i]) {
          t+=1;
          ans = max(ans, t);
          //cout << "A" << endl;
        } else {
          t=0;
          //cout << i << endl;
        }
      	b4 = v[i];
    }
    cout << ans << endl;
}