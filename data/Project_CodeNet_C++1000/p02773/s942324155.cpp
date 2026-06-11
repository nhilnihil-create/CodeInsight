#include <bits/stdc++.h>
#define ll long long 
#include<vector>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int mod=1e9+7;
int main(){
	IOS;
	int n;
	cin>>n;
	string s;
int freq=0;
map <string,int> m;
for(int i=0;i<n;i++)
{
	cin>>s;
		auto it=m.find(s);
	if(it!=m.end()){
	it->second++;
	if(it->second>=freq)
	freq=it->second;
	}
	else
	m.insert(make_pair(s,0));
}

vector<string> v;
for(auto i:m){
	if(i.second==freq)
	cout<<i.first<<endl;
}
}