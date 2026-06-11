#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
//using ll = long long;
//using P = pair<int,int>;

int main(){
	int n;
	cin >> n;
	string s;
	cin >> s;
	int counts =0;
	rep(i,s.size()-2){
		if(s[i] == 'A' && s[i+1] == 'B' && s[i+2] == 'C') counts ++;
	} 
	cout << counts << endl;
}