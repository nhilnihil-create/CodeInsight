#include<bits/stdc++.h>
using namespace std;

const int N = 200005;
typedef long long ll;


int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	string s;
	cin>>s;
	deque<char> dq;
	for(int i=0;i<(int)s.size();i++){
		dq.push_back(s[i]);
	}
	bool rev = false;
	
	int q;
	cin>>q;
	while(q--){
		int t;
		cin>>t;
		if(t == 1){
			rev ^= 1;
		}else{
			int f;
			cin>>f;
			char c;
			cin>>c;
			if(f == 1){
				if(rev) dq.push_back(c);
				else dq.push_front(c);
			}else{
				if(rev)dq.push_front(c);
				else dq.push_back(c);
			}
		}
	}
	
	if(!rev){
		while(!dq.empty()){
			cout<<dq.front();
			dq.pop_front();
		}
	}else{
		while(!dq.empty()){
			cout<<dq.back();
			dq.pop_back();
		}
	}
	cout<<endl;
	return 0;
}
