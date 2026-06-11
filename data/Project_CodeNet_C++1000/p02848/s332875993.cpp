#include<iostream>
#include<vector>
#include<bits/stdc++.h>
#define lli long long int
#define mod 1000000007
#define pb push_back
#define mk make_pair
#define fastio ios_base::sync_with_stdio(false); cout.tie(NULL);
using namespace std;

int main()
{
	fastio;
	int n;
	string s;
	cin>>n>>s;
	for(auto ch : s)
		cout<<(char)((ch-'A'+n)%26+'A');
	return 0;
}
