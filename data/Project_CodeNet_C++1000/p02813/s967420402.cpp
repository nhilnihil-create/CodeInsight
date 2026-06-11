 
/***************************************** 
****       Solution by SlavicG        ****
*****************************************/
 
#include <bits/stdc++.h>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm> 
#include <set>
#include <utility>
#include <queue>
#include <map>
#include <assert.h>
#include <stack>
using namespace std;
#define ll long long
#define forn(i,n) for(int i=0;i<n;++i)
#define MX 10000000001
#define pow2(a) ((a)*(a))
#define pb push_back
#define vair <vector<pair<int,int>>
#define vi vector<int>
#define mp make_pair
#define pf push_front
#define all(v) v.begin(), v.end()
#define endl "\n"
#define FAST std::ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define PI   3.14159265
#define _Yes printf("YES\n");
#define _No printf("NO\n");
#define scanline; scanf(" %[^\n]s\n",s);
#define print3(x,y,z); cout << x << " " << y << " " << z << endl;
const ll MOD = 1000000007;
 int longestIncreasingSubsequenceLenghtDP(int a[],int n){
    int dp[n],ans=0;
    for(int k = 0;k<n;k++){
        dp[k] = 1;
        for(int i = 0;i<k;i++){
            if(a[i] <= a[k]){
                dp[k] = max(dp[k],dp[i] + 1);
                ans = max(dp[k],ans);
            }
        }
    }
    return ans;
 }
int result[1000] = {0};
int factDP(int n) {
   if (n >= 0) {
      result[0] = 1;
      for (int i = 1; i <= n; ++i) {
         result[i] = i * result[i - 1];
      }
      return result[n];
   }
}
bool isPrime(ll n){
    if(n<2) return false;
    for(ll x = 2;x*x <=n;x++){
        if(n%x == 0)return false;
    }
    return true;
}
vector<int> primeFactors(int n){
    vector<int> f;
    for(int x = 2;x*x<=n;x++){
        while(n%x==0){
            f.push_back(x);
            n/=x;
        }
    }
    if(n>1)f.push_back(n);
    return f;
}
bool isPerfectSquare(long double x) {   
  long double sr = sqrt(x); 
  return ((sr - floor(sr)) == 0); 
} 
int isSubstring(string s1, string s2) { 
    int M = s1.length(); 
    int N = s2.length(); 
    for (int i = 0; i <= N - M; i++) { 
        int j; 
        for (j = 0; j < M; j++) 
            if (s2[i + j] != s1[j]) 
                break; 
        if (j == M) 
            return true; 
    } 
    return false; 
} 
vector<int> primes;
void SieveOfEratosthenes(int n) { 
    bool prime[n+1]; 
    memset(prime, true, sizeof(prime)); 
    for (int p=2; p*p<=n; p++) {  
        if (prime[p] == true) { 
            for (int i=p*p; i<=n; i += p) 
                prime[i] = false; 
        } 
    } 
    for (int p=2; p<=n; p++) 
       if (prime[p]) 
          primes.pb(p);
}
bool isSubSequence(string str1,string str2, int m, int n) 
{ 
    if (m == 0) return true; 
    if (n == 0) return false; 
    if (str1[m-1] == str2[n-1]) 
        return isSubSequence(str1, str2, m-1, n-1); 
		
    return isSubSequence(str1, str2, m, n-1); 
}
ll fastExpo(ll a,ll n, ll MOD)
{
	ll ans = 1;
	while(n>=1)
	{
		if(n%2==0)
		{
			n/=2LL;
			a = (a * a) % MOD;
		}else
		{
			--n;
			ans = (ans*a) % MOD;
		}
	}
	return ans;
}
int main()
{
	int n;
	cin >> n;
	int a[n],b[n];
	for(int i = 0;i<n;i++)
	{
		cin >> a[i];
	}
	for(int i = 0;i<n;i++)
	{
		cin >> b[i];
	}
	int aa,bb;
	int arr[n];
	for(int i = 0;i<n;i++)
	{
		arr[i] = i+1;
	}
	int cnt = 0;
    do 
	{ 
		cnt++;
		bool ok = true;
		//check for a
		for(int i =  0;i<n;i++)
		{
			if(arr[i] != a[i])ok = false;
		}
		if(ok)aa=cnt;
		ok = true;
		for(int i=  0;i<n;i++)
		{
			if(arr[i] != b[i])ok = false;
		}
		if(ok)bb=cnt;
    } while (next_permutation(arr, arr + n)); 
	cout << abs(aa-bb) << endl;
}