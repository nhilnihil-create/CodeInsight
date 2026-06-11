#include <bits/stdc++.h>
#include <iostream>
typedef long long ll;
#define rep(i,a,b) for(ll i =a ;i <= b;i++)
#define per(i,a,b) for(ll i =a ;i >= b;i--)
using namespace std;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;



bool solve(vvi matrix, unordered_map<int,bool> num_map)
{
	int rcount=0 , ccount=0, dcount=0;
	rep(i, 0, 2)
	{
		rcount=0 , ccount=0;
		rep(j,0,2){
			if(num_map[matrix[i][j]] == true)
				rcount++;

			if(num_map[matrix[j][i]] == true)
				ccount++;

			if(i==j && num_map[matrix[i][j]] == true)
				dcount++;
		}
		if(rcount == 3 || ccount == 3)
			return true;
	}

	if(dcount == 3)
		return true;
	dcount = 0;
	rep(i, 0, 2)	
		if(num_map[matrix[2 - i][i]])
			dcount++;

	if(dcount == 3)
		return true;
	return false;
}

int main(int argc, char const *argv[])
{
	//ifstream cin("input.txt");
	
	vvi matrix(3, vi(3));
	unordered_map<int, bool> num_map;
	rep(i,0,2){
		rep(j,0,2)
		{
			cin>>matrix[i][j];
			num_map[matrix[i][j]] = false;
		}
	}
	int n, b;
	cin>>n;
	rep(i, 0, n-1)
	{
		cin>>b;
		num_map[b] = true;
		if(solve(matrix, num_map)){
			cout<<"Yes";
			return 0;
		}

		
	}
	cout<<"No";
}