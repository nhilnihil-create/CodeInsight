#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> P;
typedef long long ll; 


int main(){
	ll n,k;
	ll r,s,p;
	string t;
	cin >> n >> k;
	cin >> r >> s >> p;
	cin >> t;

	ll max = 0;
	for(int i=0;i<t.length();i++){
		if(t[i]=='r') max += p;
		if(t[i]=='s') max += r;
		if(t[i]=='p') max += s;
	}

	for(int i=0;i<k;i++){
		for(int j=i;j+k<t.length();j+=k){
			if(t[j]==t[j+k]){
				if(t[j]=='r') max -= p;
				if(t[j]=='s') max -= r;
				if(t[j]=='p') max -= s;
				t[j+k] = 'x';
			}
		}
	}

	cout << max << endl;

	return 0;
}
