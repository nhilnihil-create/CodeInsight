#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int main(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	int n;
	cin>>n;
	vector<int>ar;
	set<int>st;
	while(n--){
		int a;
		cin>>a;
		ar.push_back(a);
		st.insert(a);
	}
	if(ar.size()==st.size()) cout<<"YES";
	else cout<<"NO";
	return 0;
}
