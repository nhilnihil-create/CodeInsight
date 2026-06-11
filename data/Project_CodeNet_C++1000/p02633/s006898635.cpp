#include<bits/stdc++.h>
using namespace std ;


/*//______OPTIMISATION______//
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")*/

//________________MACROS_______________//
#define   fast 	 		ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define   int   		long long int
#define   pb  			push_back
#define   f     		first
#define   s     		second
#define   deb(x) 		cerr << #x << " " << x << endl;
#define   debb(x, y) 		cerr << #x << " = " << x << "," << #y << " = " << y << endl <<endl;
#define   in            	insert
#define   lb            	lower_bound
#define   ub            	upper_bound
#define   all(x)        	x.begin(), x.end()
#define   endl              '\n'
bool isPrime(int n)
{
	for(int i = 2; i * i <= n; i++)
	{
		if(n % i == 0)
		{
			return false;
		}
	}
	return true;
}

bool isPowerOfTwo (int x)
{
    return (x && (!(x&(x-1))));
}

int countDigit(int num)
{
	return (floor(log10(num)) + 1);
}

int rightMostFirstSetBit (int n)
{
    return log2(n & -n)+1;
}

int noOfBitInBinaryRepresntation(int n)
{
    return log2(n)+1;
}
signed main()
{
    fast ;

    int test_case = 1;
    //cin >> test_case;

    while (test_case--)
    {
        int n ;
        cin >> n ;
        int l= (n * 360) / __gcd( n , (int)360) ;
        cout <<l / n << endl;
    }
    return 0;
}

