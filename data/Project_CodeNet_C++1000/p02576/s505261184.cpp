#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define v(x) vector<x>
#define pb push_back 
#define mp make_pair
#define maxint 1e18
#define mint -1e18

int main(){
	int n,x,t;
	cin>>n>>x>>t;
	
	int cnt = ceil((double)n/x);
	cout<<cnt*t<<'\n';


	return 0;
}