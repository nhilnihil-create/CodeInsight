#include <bits/stdc++.h>
using namespace std;
int main(){
  	string s,t,a[]={"Yes","No"};
  	int c=0;
  	cin >> s >> t;
  	for(int i=0;i<s.size();i++){
      	if(s[i]!=t[i]){
        	c++; break;
        }
    }
  	cout << a[c] << endl;
  	return 0;
}