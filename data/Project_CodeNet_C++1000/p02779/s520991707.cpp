#include<bits/stdc++.h>
//#include<iostream>
using namespace std;

typedef long long ll;
const int N = 2000006;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int n;
	set<int> s;
	cin>>n;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		s.insert(x);
	}
	if((int)s.size() == n){
		cout<<"YES";
	}
	else{
		cout<<"NO";
	}
	
	return 0;
}
