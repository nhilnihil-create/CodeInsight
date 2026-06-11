// AUTHOR : Kishan Srivastav
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define in freopen("input.txt", "r", stdin)
#define out freopen("output.txt", "w", stdout)
#define ios ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);


int main() {
	ios
#ifndef ONLINE_JUDGE
	in;
	out;
#endif
	string s;
	cin>>s;
	for (int i = 0; i < s.length(); i++){
		if(i % 2 == 0 ){
			if(s[i]=='L'){
				cout<<"No"<<endl;
				return 0;
			}
		}else{
			if(s[i] == 'R'){
				cout<<"No"<<endl;
				return 0;
			}
		}
	}
	cout<<"Yes"<<endl;
	return 0;
}