#include<iostream>
#include<stdio.h>
#include<cstring>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<math.h>
#define ll long long 
#define d double
using namespace std;

int main()
{
	
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n,m;
    cin>>n>>m;
    
    n-=1;
    m-=1;
    
    int s1= n*(n+1)/2;
    int s2= m*(m+1)/2;
    
    cout<<s1+s2<<endl;
    
    return 0;
    
}
    