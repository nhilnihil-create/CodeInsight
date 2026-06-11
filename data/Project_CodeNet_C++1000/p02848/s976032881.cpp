#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 10000002
bool prime[N];

//check prime
bool isPrime(ll n)
{
	if(n<=1)return false;
	for(ll i=2;i*i<=n;i++)
	{
		if(n%i==0)return false;
	}
    return true;
}
//gcd
ll gcd(ll x,ll y)
{
	if(x==0)return y;
	else return gcd(y%x,x);
}
//lcm;
ll lcm(ll x,ll y)
{
	return x*y/gcd(x,y);
}

// sieve of eratosthenes
void sieve(vector<ll> &v)
{
	memset(prime,true,N);
	prime[0]=prime[1]=false;
	for(ll i=2;i*i<N;i++)
	{
		if(prime[i]==true)
		{
			for(ll j=i+i;j<N;j+=i)
			{
				prime[j]=false;
			}
		}
	}
	for(ll i=0;i<N;i++)
	{
		if(prime[i]==true)
		{
			v.push_back(i);
		}
	}
}

//count sum & divisor

ll countDivisor(vector<ll> &v,ll n)
{
	
	for(ll i=1;i*i<=n;i++)
	{
		if(i*i==n)
		{
			v.push_back(i);
		}
		else if(n%i==0)
		{
			v.push_back(i);
			v.push_back(n/i);
		}
	}
}

//primeFactorization

ll primeFactorization(vector<ll> &v,ll n)
{
	while(n%2==0)
	{
		v.push_back(2);
		n/=2;
	}
	for(ll i=3;i*i<=n;i=i+2)  
    {  
        while(n%i==0)  
        {  
			v.push_back(i); 
            n = n/i;  
        }  
    } 
	if(n>2)
    {
    	v.push_back(n);	
	}
}

//Palindrome check string
bool isPalindrome(string s)
{
	int l=0;
	int h=s.size()-1;
	while(l<h)
	{
		if(s[l++]!=s[h--])
		{
			return false;
		}
	}
	return true;
	
}

int main()
{
	ll n,x;
	cin>>n;
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		x=(s[i]-'A'+n)%26;
		//cout<<x;	
		cout<<(char('A'+x));
	}
	cout<<endl;
	
}
