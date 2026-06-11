#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
const int maxn = 100010;
typedef long long ll;

int n,m,k;
int sum;
int mod;
int a[maxn];

void test(const int A[])
{
	for (int i=1;i<=n;i++)
		cout << A[i] << " ";
	cout << endl;
}

void test(const vector<int> V)
{
	for (int i=0;i<V.size();i++)
		cout << V[i] << " ";
	cout << endl;
}

void solve()
{
	scanf("%d %d %d",&n,&m,&sum);
	
	for (int i=0;i<m;i++)
	{
		cout << sum << " ";
	}
	if(sum == 1000000000)
	{
		for (int i=0;i<n-m;i++)
		{
			cout << sum-1 << " ";
		}
		cout << endl;
	} 
	else
	{
		for (int i=0;i<n-m;i++)
		{
			cout << sum+1 << " ";
		}
		cout << endl;
	}
}

int main()
{
	int t;
	t = 1;
	while(t--)
	{
		solve();
	}
} 