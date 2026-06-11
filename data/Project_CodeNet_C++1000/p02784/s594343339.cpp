#include <bits/stdc++.h>
using namespace std;
 
int main(){
	int n,h,res=0;
  	cin >> h >> n;
  	vector<int> s(n);
  	for(int i=0;i<n;i++){
    	cin >> s.at(i);
      	res += s.at(i);
    }
  	if(res >= h) cout << "Yes" << endl;
  	else cout << "No" << endl;
}