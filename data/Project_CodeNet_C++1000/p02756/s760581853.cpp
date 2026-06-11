#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin, (x).rend()
#define endl '\n'
typedef long long ll;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	string s; cin>>s;
	int size = s.size();
	deque<char> dq(size);
	for(int i=0; i<size; i++){
		dq[i] = s[i];
	}	
	int c, n; cin>>c;
	bool change = false;
	while(c--){
		cin>>n;
		if(n==1){
			change = !change;
		}
		else{
			int ind; cin>>ind;
			char x; cin>>x;
			if(change)ind==1?ind++:ind--;
			if(ind == 1)dq.push_front(x);
			else dq.push_back(x);
		}
	}
	if(change){
		int tam = dq.size();
		for(int i=tam-1; i>=0; i--){
			cout<<dq[i];
		}
		cout<<endl;
	}
	else{
		for(auto&x: dq){
			cout<<x;
		}
		cout<<endl;
	}
}
