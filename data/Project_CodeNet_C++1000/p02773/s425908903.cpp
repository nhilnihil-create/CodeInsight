#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin>>n;
	string s;
	map<string, int> m;
	int maior = 0;
	while(n--){
		cin>>s;
		m[s]++;
		if(m[s] > maior)
			maior = m[s];
	}
	set<string> s1;
	for(auto it: m){
		if(it.second == maior){
			s1.insert(it.first);
		}
	}
	for(auto it: s1){
		cout<<it<<endl;
	}
	
	return 0;
}