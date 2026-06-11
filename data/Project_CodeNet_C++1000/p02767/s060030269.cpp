#include <bits/stdc++.h>
#include <iostream>
typedef long long ll;
#define rep(i,a,b) for(ll i =a ;i <= b;i++)
#define per(i,a,b) for(ll i =a ;i >= b;i--)
using namespace std;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;




int main()
{
	//ifstream cin("input.txt");
	int n;
	cin>>n;
	vi nums(n);
	rep(i,0,n-1)
		cin>>nums[i];

	int mi = *(min_element(nums.begin(), nums.end()));
	int mx = *(max_element(nums.begin(), nums.end()));
	int mid = (mx+mi)/2;
	ll sum = 0, min_sum = INT_MAX;
	rep(x, mi,mx)
	{
		sum = 0;
		for(int i : nums)
			sum += (x - i)*(x - i);

		min_sum = min(sum, min_sum);
	}
	

	cout<<min_sum;
	
}