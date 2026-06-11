#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	set<int>st;int t=3;
	while(t--){
		int a;cin>>a;
		st.insert(a);}
	cout<<(st.size()!=2? "No":"Yes");
}
