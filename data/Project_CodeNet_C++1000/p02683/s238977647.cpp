#include <bits/stdc++.h>
#include <iostream>
typedef long long ll;
#define rep(i,a,b) for(ll i =a ;i <= b;i++)
#define per(i,a,b) for(ll i =a ;i >= b;i--)
using namespace std;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

vi C, X;
vvi A;
int n,m,x;

int findMinCost(int index)
{
	//cout<<index<<"\n";
	bool flag = true;
	rep(i, 0, m - 1)
	{
		if(X[i] > 0){
			flag = false;
			break;
		}
	}
	if(flag){
			return 0;
		}

	if(index > n - 1)
		return INT_MAX;

	
	rep(i, 0, m - 1)
	{
		X[i] -= A[index][i];
	}
	int min_cost =  findMinCost(index+1);
	if(min_cost != INT_MAX)
		min_cost += C[index];
	rep(i, 0, m - 1)
	{
		X[i] += A[index][i];
	}

	return min(min_cost, findMinCost(index + 1));
}


int main(int argc, char const *argv[])
{
	//ifstream cin("input.txt");
	
	cin>>n>>m>>x;
	C = vi(n);
	A = vvi(n,vi(m));

	rep(i ,0, n - 1)
	{
		cin>>C[i];
		rep(j, 0, m - 1)
			cin>>A[i][j];
	}

	X = vi(m , x);
	int min = findMinCost(0);
	if(min == INT_MAX)
		cout<< -1;
	else
		cout<<min;


}