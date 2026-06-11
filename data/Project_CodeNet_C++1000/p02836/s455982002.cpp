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
	int len = s.length();
	int l = 0;
	int r = len-1;
	int count = 0;
	while(l<r){
		if (s[l] != s[r]){
			count++;
		}
		l++;
		r--;
	}
	cout<<count<<endl;
}