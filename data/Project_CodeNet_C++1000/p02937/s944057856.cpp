#include <bits/stdc++.h>
using namespace std;
#define int long long int
main() {
	string s;
	string t;
	cin>>s>>t;
	int val[s.size()][26];
	int pos[26];
	for(int i=0; i<26; i++){
		pos[i]=-1;
	}
	for(int i=0; i<s.size(); i++){
		for(int j=0; j<26; j++){
			val[i][j]=-1;
		}
	}
	
	for(int i=s.size()-1; i>=0; i--){
		for(int j=0; j<26; j++){
			val[i][j]=pos[j];
		}
		pos[(s[i]-'a')]=i;
	}
	
	
	int position=-1;
	int ans=0;
	
	int i=0;
	
	while(i<t.size()){
		
		if(pos[(t[i]-'a')]==-1){
			cout<<-1;
			return 0;
		}
		if(position==-1){
			
			int place=pos[(t[i]-'a')];
			ans+=(place+1);
			position=place;
			
			i++;
			continue;
		}
		int place=val[position][(t[i]-'a')];
		
		if(place==-1){
		
			ans+=(s.size()-position-1);
			position=-1;
			continue;
		}
		ans+=(place-position);
		position=place;
		i++;
	}
	cout<<ans;
	return 0;
}