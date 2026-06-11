/**Bismillahir Rahmanir Rahim.**/
#include<bits/stdc++.h>
#define ll 	 long long
#define pb push_back
#define mp make_pair
using namespace std;

int main() 
{ 

int n; cin>>n;
string x; cin>>x;

for(int i=0; i<x.size(); i++)
{
	x[i]+= n;
	
if(x[i]-'A'>=26) x[i]-=26;
	
	cout<<x[i];
}


    return 0;
} 
