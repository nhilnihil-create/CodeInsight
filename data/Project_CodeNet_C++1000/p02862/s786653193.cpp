#include <bits/stdc++.h>
using namespace std;

const int combination_max=1000000+1000000+2;
const int combination_modulo=1000000007;
vector<int64_t> factorials(combination_max);
vector<int64_t> factorials_inv(combination_max);
vector<int64_t> inverse(combination_max);
int combination_mod(int n, int k);
int prepare_combination_mod();

int main()
{
	int x,y;
	cin >> x >> y;

	if ( ((2*x-y)%3!=0) && ((2*y-x)%3!=0) )
	{
		cout << 0 << endl;
		return 0;
	}

	int n1,n2;
	n2=(2*x-y)/3;
	n1=(2*y-x)/3;

	if ((n1<0)||(n2<0))
	{
		cout << 0 << endl;
		return 0;
	}

	prepare_combination_mod();
	cout << combination_mod(n1+n2,n1) << endl;
}

int prepare_combination_mod()
{
	factorials[0]=1;
	factorials[1]=1;
	factorials_inv[0]=1;
	factorials_inv[1]=1;
	inverse[1]=1;
	for (int i=2;i<combination_max;++i)
	{
		factorials[i]=factorials[i-1]*i%combination_modulo;
		inverse[i]=combination_modulo - inverse[combination_modulo%i]*(combination_modulo/i)%combination_modulo;
		factorials_inv[i]=factorials_inv[i-1]*inverse[i]%combination_modulo;
	}
	return 0;
}

int combination_mod(int n, int k)
{
	return factorials[n]*(factorials_inv[k]*factorials_inv[n-k]%combination_modulo)%combination_modulo;
}





