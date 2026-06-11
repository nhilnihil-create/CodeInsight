#include<bits/stdc++.h>
#include<vector>
#include<iostream>
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
#define quick ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;

//bool checkprime(int n) 
//{ 
//    if (n <= 1) 
//        return false; 
//    for (int i = 2; i < n; i++) 
//        if (n % i == 0) 
//            return false; 
//  
//    return true; 
//} 

int main() 
{ 
	string s;
	cin>>s;
	int n=s.length();
	if(s[n-1]=='s')
	{
		s=s+"es";
	}
	else
	{
		s+='s';
	}
	cout<<s;
	
return 0; 
} 