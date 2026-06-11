
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
#define sort(v)     sort((v).begin(),(v).end())
#define rall(v)     (v).rbegin(),(v).rend()
#define rsort(v)     sort((v).rbegin(),(v).rend())
#define gcd(a,b)    __gcd((a),(b))
#define minn(v)     *min_element(v.begin(), v.end());
#define maxx(v)     *max_element(v.begin(), v.end());
#define print(x)    cout<<(x)<<endl;
typedef pair<int,int> pii;  
typedef vector<int> vi;
//x.substr(start, length);
/*
// Create a vector containing n 
//vectors of size m.  
    vector<vector<int> > vec( n , vector<int> (m, 0));  
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
signed main() 
{
    fastio;
    //cout << fixed << setprecision(0);
    vector<pair<string,int>>a;
    int n;
    cin>>n;
    f(i,n)
    {
        string s;
        int x;
        cin>>s>>x;
        a.pb({s,x});
    }
    string c;
    cin>>c;
    int t=-1;
    for(int i=0;i<n;i++)
    {
        if(a[i].F==c)
        {
            t=i;
            break;
        }
    }
    
    int ans=0;
    for(int i=t+1;i<n;i++)
    {
        ans+=a[i].S;
    }
    cout<<ans<<endl;
    
}
