#include "bits/stdc++.h"
 
using namespace std;
 
using ll = long long;
 
#define all(x) begin(x), end(x)
#define rot(s, k) rotate(s.begin(), s.begin()+ s.size()-(k%s.size()), s.end()); 

bool ispal(string s){
	string t = s;
	reverse(all(t));
	return t == s;
}
 
int main(){
ios_base::sync_with_stdio(0); cin.tie(0);
string s; cin >> s;
int n = s.size();
if(ispal(s) && ispal(s.substr(0,(n-1)/2)) && ispal(s.substr((n+1)/2)))
	cout << "Yes" << "\n";
else cout << "No" << "\n";


 
}