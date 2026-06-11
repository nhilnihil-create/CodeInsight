#include <bits/stdc++.h>
using namespace std;

int main(){
	long long int   K;
	string S;
	cin >> K >> S;
  
  if (K >= S.size()) cout << S << endl;
  else {
  	while (S.size() > K) S.pop_back();
    S += "...";
    cout << S << endl;
  }
}
