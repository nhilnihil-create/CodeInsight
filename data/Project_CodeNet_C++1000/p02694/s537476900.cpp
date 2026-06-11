#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll x, acc=100, i;
int y=0;
int main() {
	cin >> x;
  	while (acc<x) {
       	y++;
      	i=acc/100;
      	acc+=i;
       //cout << y << " " << acc << "\n";
    }
  	cout << y;
}