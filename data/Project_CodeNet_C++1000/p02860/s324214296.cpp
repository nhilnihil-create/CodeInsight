#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    string s;
   	cin >> n;
   	cin >> s;
   	if(n % 2 == 1){
   		cout << "No" << "\n";
   	}else{
   		int pos = (n/2);
   		string s1 = s.substr(0, pos);
   		string s2 = s.substr(pos, n-1);
   		if(s1.compare(s2) == 0){
   			cout << "Yes" << "\n";
   		}else{
   			cout << "No" << "\n";
   		}
   	}
   	return 0;
}