#include <bits/stdc++.h>
using namespace std;

int main() {
	int H,A;
	cin >> H >> A;

  	int ans=0;
  	if(H <= 0){
      cout << ans << endl;
      return 0;
    }
  	while(H>0){
      ans ++;
      H -= A;
    }
  	cout << ans << endl;
}
