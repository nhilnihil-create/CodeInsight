#include<bits/stdc++.h>
using namespace std;
map<string,int>m;
map<string,int>::iterator it; 
int main(){
	int n;
	cin>>n;
	long long ret = 0;
	while(n--){
		string s;
		cin>>s;
		sort(s.begin(),s.end());
		it = m.find(s);
		if(it!=m.end()){
			ret+=it->second;
			it->second+=1;
		}
		else m.insert(make_pair(s,1));
	}
	cout<<ret;
}