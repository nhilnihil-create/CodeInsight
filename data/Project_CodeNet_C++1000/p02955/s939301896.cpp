#include <bits/stdc++.h>

using namespace std;

long long int gcd(long long int a,long long int b)
{
	if(b==0)
	{
		return a;
	}
	return gcd(b,a%b);
}

int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	int n,k;
	long long int t;
	vector <long long int> v;
	long long int sum = 0;
	long long int res = 0;
	cin >> n >> k;

	for(int i=0;i<n;i++)
	{
		cin >> t;
		sum += t;
		res = gcd(res,t);
		v.push_back(t);
	}	

	vector <long long int> a;
	for(int i=1;i<=sqrt(sum);i++)
	{
		if(sum%i==0)
		{
			if(sum/i==i)
			{
				a.push_back(i);
			}
			else
			{
				a.push_back(i);
				a.push_back(sum/i);
			}
		}
	}

	sort(a.begin(),a.end());
	for(int i=0;i<a.size();i++)
	{
		vector <long long int> temp;
		for(int j=0;j<n;j++)
		{
			int kk = (v[j]%a[i]);
			temp.push_back(kk);
			/*
			if(kk<=a[i]-kk)
			{
				pos += kk;
			}
			else
			{
				neg += (a[i] - kk);
			}
			*/
		}
		sort(temp.begin(),temp.end());
		for(int j=0;j<n;j++)
		{
			long long int cnt = 0;
			long long int pos = 0;
			long long int neg = 0;
			for(int K=0;K<temp.size();K++)
			{
				if(K<=j)
				{
					pos += temp[K];
				}
				else
				{
					neg += (a[i] - temp[K]);
				}
			}
			if(pos<=neg)
			{
				cnt += pos;
				neg-=pos;
				if(neg%a[i]==0)
				{
					cnt += neg;
					if(cnt <= k)
					{
						res = max(res,a[i]);
						break;
					}
				}
			}
			else
			{
				cnt += neg;
				pos-=neg;
				if(pos%a[i]==0)
				{
					cnt += pos;
					if(cnt <= k)
					{
						res = max(res,a[i]);
						break;
					}
				}
			}
		}
	}

	cout << res << '\n';

	return 0;
}
