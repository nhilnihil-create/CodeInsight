#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
map<string, bool> gacha;
int n, d=0; string s;
int main() {
	cin >> n;
  	while (n--) {
       	cin >> s;
      	if (!gacha[s]) {
          gacha[s]=1; d++;
        }
    }
  	cout << d;
}