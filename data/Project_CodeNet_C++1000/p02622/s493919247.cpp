	#include<bits/stdc++.h>
	#include<vector>
	#include<string>
	#include<math.h>
	#define ll long long int 
	#define loop(a,b,i) for(int i=a;i<b;i++)
	#define loopr(a,b,i) for(int i=n-1;i>=0;i--)
	#define pb push_back
	#define db double
	#define mp make_pair
	#define endl "\n"
	#define f first
	#define se second
	#define all(x) x.begin(),x.end()
	#define MOD 1000000007
	#define N 8
	#define quick ios_base::sync_with_stdio(false);cin.tie(NULL)
	using namespace std;
	
//	bool isPrime(int n)
//	{
//    	if(n <= 1) return false;
//     	if(n == 2) return true;
//    	if(n % 2 == 0) return false;
//    	for(int j = 3; j <= sqrt(n); j++)
//		{
//    		if(n % j == 0) return false;
//    	}	
//    	return true;
//	}
	
	
	int main() 
	{ 
		string s,h;
		cin>>s>>h;
		int n=s.length();
		int i,cnt=0;
		for(i=0;i<n;i++)
		{
			if(s[i]!=h[i])
				cnt++;
		}
		cout<<cnt;
	return 0; 
	} 