#include <bits/stdc++.h>
using namespace std;
 
int main(){
	int n,m;
  	cin >> n >> m;
  	vector<int> a(m);
   int res=0;
  	for(int i=0;i<m;i++){
      cin >> a.at(i);
      res += a.at(i);
      }
  	res = n - res;
  	if(res>=0)cout << res <<endl;
  	else cout << -1 << endl;
}