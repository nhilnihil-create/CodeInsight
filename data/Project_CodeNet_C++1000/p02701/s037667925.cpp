#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	set<string> s;
	string word;
	for(int i=1;i<=n;i++){
		cin>>word;
		s.insert(word); 
	}
	cout<<s.size()<<'\n';
	return 0;
}