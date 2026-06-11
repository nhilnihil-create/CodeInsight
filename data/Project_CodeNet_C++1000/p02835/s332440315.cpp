#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define int         long long   
#define double      long double
#define endl        "\n"
#define pb          push_back
#define PI          3.1415926535897932384626433832795l
#define F           first
#define S           second
#define mp          make_pair
#define f(i,n)      for(int i=0;i<n;i++)
#define fastio      ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define all(v)      (v).begin(),(v).end()
#define rall(v)     (v).rbegin(),(v).rend()
#define gcd(a,b)    __gcd((a),(b))
#define minn(v)     *min_element(v.begin(), v.end());
#define maxx(v)     *max_element(v.begin(), v.end());
#define print(x)    cout<<(x)<<endl;
#define sum(v)+x    accumulate(v.begin(), v.end(),x);
typedef pair<int,int> pii;  
typedef vector<int> vi;
//x.substr(start, length);
/*
Create a vector containing n 
vectors of size m.  
---vector<vector<int> > vec( n , vector<int> (m, 0));  
*/
 
/*left shifting an integer “x” with an integer “y” (x<<y) 
    is equivalent to multiplying x with 2^y (2 raise to power y).*/
/*Similarly right shifting (x>>y) is equivalent 
    to dividing x with 2^y.
*/
 
struct type{
    int k, i, j;
};
//to check if a no is prime or not?
bool isPrime(int n) 
{ 
    if (n <= 1) 
        return false; 
    if (n <= 3) 
        return true; 
    if (n % 2 == 0 || n % 3 == 0) 
        return false; 
  
    for (int i = 5; i * i <= n; i = i + 6) 
        if (n % i == 0 || n % (i + 2) == 0) 
            return false; 
  
    return true; 
}
 
// minimum subaaray sum of size k-sliding window approach
int findSubarray(int arr[], int n, int k)
{
	int window_sum = 0;
	int min_window = INT_MAX;
	int last = 0;
	for (int i = 0; i < n; i++)
	{
		window_sum += arr[i];
		if (i + 1 >= k)
		{
			if (min_window > window_sum)
			{
				min_window = window_sum;
				last = i;
			}
			window_sum -= arr[i + 1 - k];
		}
	}
	int sum=0;
	for(int i=last-k+1;i<=last;i++)
	{
	    sum+=arr[i];
	}
	return sum;
}
//finds the next permutation to given sequence of nos
int nextpermutation(vi v)
{
    vi t=v;
    sort(all(t));
    int x=0;
    while(true)
    {
        x++;
        if(t==v)
        {
            return x;
        }
        next_permutation(all(t));
    }
}
vector<int>factors(int n) 
{ 
    // Note that this loop runs till square root 
    vi ans;
    for (int i=1; i<=sqrt(n); i++) 
    { 
        if (n%i == 0) 
        { 
            if (n == i*i )ans.pb(i);
            else
            {
                ans.pb(i);
                if (i!=n/i)ans.pb(n/i);
            }
        } 
    } 
    return ans;
}
int power(int x, int y, int p)  
{  
    int res = 1;     // Initialize result  
  
    x = x % p; // Update x if it is more than or  
                // equal to p 
   
    if (x == 0) return 0; // In case x is divisible by p; 
  
    while (y > 0)  
    {  
        // If y is odd, multiply x with result  
        if (y & 1)  
            res = (res*x) % p;  
  
        // y must be even now  
        y = y/2; // y = y/2  
        x = (x*x) % p;  
    }  
    return res;  
}
// Recursive C++ program to check if a string is subsequence of another string 
bool isSubSequence(char str1[], char str2[], int m, int n) 
{ 
    // Base Cases 
    if (m == 0) return true; 
    if (n == 0) return false; 
  
    // If last characters of two strings are matching 
    if (str1[m-1] == str2[n-1]) 
        return isSubSequence(str1, str2, m-1, n-1); 
  
    // If last characters are not matching 
    return isSubSequence(str1, str2, m, n-1); 
} 
signed main() 
{
    fastio;
    cout << fixed << setprecision(12);
    int a,b,c;
    cin>>a>>b>>c;
    if(a+b+c>=22)print("bust")
    else print("win")
    
    
    
    
}