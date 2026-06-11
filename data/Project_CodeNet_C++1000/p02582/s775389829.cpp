#include <bits/stdc++.h>

using namespace std;

int main() {
	string n;
	cin >> n;
  
  	long long best = 0;
  	long long curr = 0;
  	
  	for (int i = 0; i < n.length(); i++) {
      if (n[i] == 'R')
        curr++;
      else {
        best = max(best, curr);
        curr = 0;
      }
      best = max(best, curr);
      
    }
  
  	cout << best << endl;
		
}