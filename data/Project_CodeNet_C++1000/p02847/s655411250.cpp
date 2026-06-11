#include <bits/stdc++.h>
#include <string.h>
#define ll long long
using namespace std;
struct value
{
	ll x;
	ll y;
};
bool compare(value a, value b)
{
	//for descending order replace with a.roll >b.roll
	if (a.y < b.y)
		return 1;
	else
		return 0;
}
bool isPrime(int n) 
{ 
    // Corner cases 
    if (n <= 1) 
        return false; 
    if (n <= 3) 
        return true; 
  
    // This is checked so that we can skip 
    // middle five numbers in below loop 
    if (n % 2 == 0 || n % 3 == 0) 
        return false; 
  
    for (int i = 5; i * i <= n; i = i + 6) 
        if (n % i == 0 || n % (i + 2) == 0) 
            return false; 
  
    return true; 
} 
bool isPerfectSquare(long double x) 
{    
  long double sr = sqrt(x);  
  return ((sr - floor(sr)) == 0); 
} 
void pk()
{
	string s;
	cin>>s;
	if(s=="SUN")
	  {cout<<7; return;}
	if(s=="MON")
	  {cout<<6; return;}
	if(s=="TUE")
	  {cout<<5; return;}
	if(s=="WED")
	  {cout<<4; return;}
	if(s=="THU")
	  {cout<<3; return;}
	if(s=="FRI")
	  {cout<<2; return;}
	if(s=="SAT")
	  {cout<<1; return;}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	// ll t;
	// cin>>t;
	// while(t--)
	{
		pk();
	}
	
}