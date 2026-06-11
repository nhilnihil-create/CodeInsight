#include <iostream>
#include <set>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
	int n,m;
	set<string> u;
	string s;

	int k=0; //0:close 1:open

	cin>>n;
	for(int i1=0;i1<n;i1++){
		cin>>s;
		u.insert(s);
	}

	cin>>m;

	for(int i1=0;i1<m;i1++){
		cin>>s;
		if(u.find(s)!=u.end()) {
			if(k==0) {
				cout<<"Opened by "+s<<endl;
				k=1;
			}
			else {
				cout<<"Closed by "+s<<endl;
				k=0;
			}
		}
		else cout<<"Unknown "+s<<endl;

	}

	return 0;
}