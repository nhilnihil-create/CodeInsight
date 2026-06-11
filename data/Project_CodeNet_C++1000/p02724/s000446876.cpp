#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	ll yen;
  	cin >> yen;
  	ll numofhyen = floor(yen/500), numoffyen = floor((yen % 500)/5);
  cout << 1000 * numofhyen + numoffyen * 5; 
}
  