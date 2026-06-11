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
	int n;
	cin>>n;
	int a[n],b[n];
	int i,cnt=0;
	for(i=0;i<n;i++)
	{
		cin>>a[i]>>b[i];
	}
	for(i=0;i<n-2;i++)
	{
		if(a[i]==b[i] && a[i+1]==b[i+1] && a[i+2]==b[i+2])
		{
			cnt++;
		}
	}
	if(cnt>0)
	{
		cout<<"Yes";
	}
	else
	{
		cout<<"No"<<endl;
	}
	
return 0; 
} 