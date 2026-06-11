#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  	string s,t;
  	cin >> s >> t;
  	int n = s.size();
  	int q = 0;
  	for(long i = 0; i<n; i++){
      if(s[i]==t[i]){
        q++;
    }
    else{
      cout << "No" << endl;
      break;
    }
    }
  if(q==n){
    cout << "Yes" << endl;
  }
}
