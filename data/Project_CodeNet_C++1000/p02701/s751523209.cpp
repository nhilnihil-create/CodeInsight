#include<bits/stdc++.h>
using namespace std;

int main(){
	set<string>st;
	int n;
	cin>>n;
	while(n--){
		string s;
		cin>>s;
		st.insert(s);
	}
	cout<<st.size();
}