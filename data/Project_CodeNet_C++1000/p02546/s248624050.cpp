#include <bits/stdc++.h>
using namespace std;

int main(){
	string S;
	cin >> S;
  
  int s = S.size();
    char a = S.at(s - 1);
  if(a == 's'){
  cout << S << "es" << endl;
  }
  else{
  cout << S << "s" << endl;
  }
}
