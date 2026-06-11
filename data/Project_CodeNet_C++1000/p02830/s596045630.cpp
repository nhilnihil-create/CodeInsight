#include <iostream>
#include <string>
#include <vector>
#include "limits.h"
#include <cmath>
#include <algorithm>
#include <deque>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <functional>

#define mod 1000000000+7;
typedef long long ll;
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); 
	int n; string s,t,ans;
	cin >> n >> s >> t;
	for(int i{}; i<n; i++){
		ans+=s[i];
		ans+=t[i];
	}

	cout << ans << "\n";
 

}