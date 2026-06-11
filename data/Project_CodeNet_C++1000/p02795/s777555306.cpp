#include<bits/stdc++.h>                                                   //---------------------------------------------------------------
                                                                    
# define ll long long   
# define ld long double                                               
# define mod 1000000007                                                   
# define MAX 100005
# define pi 3.141592653589793238                                                                                  //shortcut keys
                                                                                
# define pb push_back                                                                     
# define mp make_pair                                                     
                                                                  
# define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);        //---------------------------------------------------------------                                       
using namespace std;

int main()
{
	int r,c,n;
	cin>>r>>c>>n;
	int x=max(r,c);
	double y=(double)n/x;
	int ans=ceil(y);
	cout<<ans;
}