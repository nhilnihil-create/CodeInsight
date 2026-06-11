#include <bits/stdc++.h>

#define pb push_back

using namespace std;

int main(){
	int n, k, c;
	vector<int> early, late;
	string s;
	cin>>n>>k>>c;
	//getline(cin, s);
	cin>>s;
	//early-greedy
	int idx = 0;
	while(early.size() < k){
		if(s[idx] == 'o'){
			early.pb(idx);
			idx+=c+1;
		}
		else{
			idx++;
		}
	}

	//late-greedy
	idx = n-1;
	while(late.size() < k){
		if(s[idx] == 'o'){
			late.pb(idx);
			idx-=c+1;
		}
		else{
			idx--;
		}
	}
	reverse(late.begin(), late.end());

	for(int i=0;i<k;i++){
		//cout<<early[i]<<" "<<late[i]<<"\n";
		if(early[i] == late[i])
			cout<<early[i]+1<<"\n";
	}
	return 0;
}