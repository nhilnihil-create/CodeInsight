#include <bits/stdc++.h> 
using namespace std; 
#define rep(i,a,b)		for(int i=a;i<=b;i++)

long long x,n;
int main() 
{ 

	ios::sync_with_stdio(false);
    cin.tie(NULL);
    int cnt=0;
    cin>>n;
    long long p = 100;
    while(p<n)
    {
    	p+=p/100;
    	cnt++;
    }
    cout<<cnt;
} 
