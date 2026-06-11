#include <bits/stdc++.h>
using namespace std;
 
int main(){
	char N[200010];
  	cin >> N;
  	int n = strlen(N);
  	int sum = 0;
  	for(int i = 0; i<n; i++){
     sum += N[i] - '0';
    }
  sum %= 9;
  if(sum == 0) cout << "Yes" << endl;
  if(sum != 0) cout << "No" << endl;
}