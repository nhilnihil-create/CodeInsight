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
    if(s[0] == s[1] || s[1] == s[2] || s[2] == s[3]) cout << "Bad";
    else cout << "Good";
    cout << endl;
    return 0;

}