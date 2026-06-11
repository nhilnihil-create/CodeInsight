#include <bits/stdc++.h>
#include<string.h>
#define ll long long 
#include<vector>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
int main(){
	IOS;
	int n;
  cin>>n;
	set<string> s;
	for(int i=0;i<n;i++)
	{
		string a;
		cin>>a;
		s.insert(a);
	}
	cout<<s.size();
	}