#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define l long
#define pb push_back
#define mp make_pair
#define mt make_tuple
ll M = 998244353;

int main() {
	// your code goes here
	//ifstream cin("input.txt");
	//ofstream cout("output.txt");
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
	
	int a[32] = {1, 1, 1, 2, 1, 2, 1, 5, 2, 2, 1, 5, 1, 2, 1, 14, 1, 5, 1, 5, 2, 2, 1, 15, 2, 2, 5, 4, 1, 4, 1, 51};

	int k; cin>>k; k--;
	cout<<a[k];
	//if(k==31) cout<<s[32];


	return 0;
}
