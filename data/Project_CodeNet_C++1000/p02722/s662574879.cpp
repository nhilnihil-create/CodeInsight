#include <bits/stdc++.h>
#define mp make_pair
#define eb emplace_back
#define fi first
#define se second
using namespace std;
using cd = complex <double>;
 
typedef pair <int, int> pii;

const int Inf = 100000000;
const long long mod = 1e9 + 7;
const double Pi = acos(-1);
 
void Fastio()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}	

long long n;
set <long long> Res;

int main()
{
	Fastio();
	cin >> n;
	for(long long i = 1; i <= 1000000; i++)
	{
		if((n - 1) % i == 0)
		{
			if(i != 1)
				Res.insert(i);
			if((n - 1) / i != 1)
				Res.insert((n - 1) / i);
		}
		if(n % i == 0)
		{
			long long temp = n;
			if(i != 1)
			{
				while(temp % i == 0)
				{
					temp /= i;
				}
				if(temp % i == 1)
				{
					Res.insert(i);
				}
			}
			temp = n;
			if((n / i) != 1)
			{
				while(temp % (n / i) == 0)
				{
					temp /= (n / i);
				}
				if(temp % (n / i) == 1)
				{
					Res.insert(n / i);
				}
			}
			
		}
	}
	cout << Res.size();
}