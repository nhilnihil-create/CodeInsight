#include <bits/stdc++.h>
#include<string.h>
#define ll long long 
#include<vector>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
int main(){
	IOS;
int n,m;
cin>>n>>m;
int votes=0;
vector<int> v(n);
for(int i=0;i<n;i++)
{
cin>>v[i];
votes+=v[i];}
sort(v.begin(),v.end(),greater<int>());
if(v[m-1]>=(votes+4*m-1)/(4*m))
cout<<"Yes";
else
cout<<"No";
	
	}