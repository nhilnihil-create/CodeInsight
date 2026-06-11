/*
Created on Thu Aug 27 21:32:39 2020

@author: roastedcoder

*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long int ull;
const int mod = 1e9+7;
const int INF = INT_MAX;
#define endl "\n"
#define append push_back
#define roastedcoder ios_base::sync_with_stdio(false); cin.tie(NULL);
//__________________________________________________________________



int main() {
	roastedcoder
	int n, x, t, res; cin>>n>>x>>t;
	res = ceil(1.0*n/x);
	cout<<res*t<<endl;
}

//__________________________________________________________________
/*
Sample Input:
20 12 6

Sample Output:
12

*/