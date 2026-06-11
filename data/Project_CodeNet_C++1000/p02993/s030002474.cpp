#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
	
	string s; cin>>s;
	s.erase(unique(s.begin(),s.end()),s.end());
	if(s.size()!=4) cout << "Bad" << endl;
	else cout << "Good" << endl;
	
}