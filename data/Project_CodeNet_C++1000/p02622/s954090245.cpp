#include <bits/stdc++.h>
using namespace std;

int main(){
	string s,r;
  	cin >> s >> r;
  	
  	int res = 0;
  	for(int i=0;i<s.size();i++){
    	if(s.at(i) != r.at(i)) res++;
    }
  	cout << res << endl;
}