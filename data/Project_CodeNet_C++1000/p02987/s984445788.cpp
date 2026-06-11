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
	set<char>st;
	for (int i = 0; i < 4; i++){
		st.insert(s[i]);
	}
	if(st.size() == 2){
		cout<<"Yes"<<endl;
	}else{
		cout<<"No"<<endl;
	}
}