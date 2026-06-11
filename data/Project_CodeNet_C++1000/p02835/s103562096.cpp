#include<bits/stdc++.h>
using namespace std;

#define ll long long
// #define endl '\n'

// void max_self(int &a, int b){a = max(a, b);}
// void min_self(int &a, int b){a = min(a, b);}

void solve(){
	int a, b, c; cin>>a>>b>>c;
	if(a + b + c >= 22){
		cout<<"bust"<<endl;
	}else{
		cout<<"win"<<endl;
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t = 1; //cin>>t;
	for(int i = 1; i<=t; i++){
		solve();
	}
	return 0;
}
