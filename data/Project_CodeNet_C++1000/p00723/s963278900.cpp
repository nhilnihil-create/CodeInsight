#include <iostream>
#include <algorithm>
#include <set>
#include <string>
using namespace std;
int main(){
	int i,j=0,n;
	for(cin>>n;j<n;j++){
		string s;
		cin>>s;
		set<string> m;
		for(i=1;i<s.length();i++){
			string s1=s.substr(0,i),s2=s.substr(i),r1=s1,r2=s2;
			reverse(r1.begin(),r1.end());
			reverse(r2.begin(),r2.end());
			m.insert(s1+s2);
			m.insert(r1+s2);
			m.insert(s1+r2);
			m.insert(r1+r2);
			m.insert(s2+s1);
			m.insert(r2+s1);
			m.insert(s2+r1);
			m.insert(r2+r1);
		}
		cout<<m.size()<<endl;
	}
}