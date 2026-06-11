#include <bits/stdc++.h>
#define ll long long 
#include<vector>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int mod=1e9+7;
int main(){
	IOS;
	int a,b,c;
	cin>>a>>b>>c;
set<int> s;
s.insert(a);
s.insert(b);
s.insert(c);

 if(s.size()==2)
cout<<"Yes";
else
cout<<"No";
}