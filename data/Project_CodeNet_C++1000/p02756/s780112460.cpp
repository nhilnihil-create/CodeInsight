#include<bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int q;
	string s;
	cin>>s;
	cin>>q;
	bool r = false;
	while(q--){
		int t;
		cin>>t;
		if(t == 1)
			r = !r;
		else{
			int f;
			char c;
			cin>>f>>c;
			if(f == 1){
				if(r){
					s.push_back(c);
				}
				else{
					s.insert(s.begin(), c);
				}
				
			}else{
				if(r){
					s.insert(s.begin(), c);
				}
				else{
					s.push_back(c);
				}
			}
		}
	}
	
	if(r){
		for(auto it = s.rbegin();it != s.rend();it++){
			cout<<*it;
		}
		cout<<endl;
	}
	else{
		cout<<s<<endl;
	}
	
	return 0;
}