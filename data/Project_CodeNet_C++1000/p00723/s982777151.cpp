#include <iostream>
#include <algorithm>
#include <set>
#include <string>
using namespace std;

#define rep(i,n) rep2(i,0,n)
#define rep2(i,m,n) for(int i=m;i<n;i++)
#define sz size()

int m;
string s;

int main(){
	cin>>m;
	while(cin>>s){
		set<string> S;
		rep(i,s.sz-1){
			string t=s.substr(0,i+1),u=s.substr(i+1);
			rep(j,2){
				rep(k,2){
					S.insert(t+u);
					S.insert(u+t);
					reverse(t.begin(),t.end());
				}
				reverse(u.begin(),u.end());
			}
		}
		cout<<S.sz<<endl;
	}
}