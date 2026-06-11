#include <bits/stdc++.h>
using namespace std;
int n , a , b , c , d , len , space , pos;
bool tuker;
string s;
int main(){
	cin >> n >> a >> b >> c >> d , pos;
	cin >> s;
    a--; b--; c--; d--;
  
	for(int i = 0 ; i < s.size() ; i++){
		if(s[i] == '#' && s[i+1] == '#' && ((a <= i && i <= c) || (b <= i && i <= d))){
      cout << "No" << endl;
      return 0;
		}
	}

  for(int i = b ; i <= d; i++){
		if(s[i] == '.' && s[i-1] == '.' && s[i] == '.' && s[i+1] == '.'){
				tuker = true;
		}
	}
  
	if(a < b && c < d )cout << "Yes" << endl;
	else if(tuker)cout << "Yes" << endl;
	else cout << "No" << endl;
}