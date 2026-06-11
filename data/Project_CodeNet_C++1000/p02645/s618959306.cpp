#include <iostream>
#include<set>
#include<vector>
#include<string>
#include<algorithm>
#include<map>

using namespace std;
const int mod = 1000000007;

int add(int a, int b)
{
	int c = a + b;
	if (c >= mod)c -= mod;
	return c;
}

int dif(int a, int b)
{
	int c = a - b;
	if (c < 0)c += mod;
	return c;
}

int mlt(int a, int b)
{
	long long c = a * 1LL * b;
	return c % mod;
}

int bp(int a, int b)
{
	if (b == 0)return 1;
	if (b % 2 == 0)
	{
		int val = bp(a, b / 2);
		return mlt(val, val);
	}
	if (b % 2 == 1)
	{
		int val = bp(a, b - 1);
		return mlt(val, a);
	}
}

int inv(int a)
{
	return bp(a, mod - 2);
}

int ibit(int mask, int i)
{
	return (mask >> i) % 2;
}

void outp(vector<vector<int>> &v)
{
	for (int i = 0; i < v.size(); i++)
	{
		for (int j = 0; j < v[i].size(); j++)cout << v[i][j] << ' ';
		cout << endl;
	}
	cout << endl;
}
void iter(vector<int>&v)
{
	int n=v.size();
	vector<int>sfadd(n);
	for(int i=0; i<n; i++)
	{
		int val=i-v[i];
		if(val>=0)
			sfadd[val]++;
		else sfadd[0]++;
		val=i+v[i];
		if(val+1<n)
			sfadd[val+1]--;
	}
	vector<int>cr(n);
	cr[0]=sfadd[0];
	for(int i=1; i<n; i++)
		cr[i]=cr[i-1]+sfadd[i];
	v=cr;
}
int main()
{
	string s;
	cin>>s;
	s.resize(3);
	cout<<s;
}