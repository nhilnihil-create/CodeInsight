// AUTHOR: ROSHAN SRIVASTAVA
// WEBSITE: https://www.youtube.com/channel/UC6uQdd7kLLOdlHSVklhV7Cw

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int x; 

int main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	cin>>x;
	x -= 400;
	cout<<(8 - x / 200)<<endl;

	return 0;
}