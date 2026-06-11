#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;
int main() {
	string s;
	cin >> s;
	int q;
	cin >> q;
	bool tt=false;
	int cnt=0;
	for(int i=0;i<q;i++){
		int t;
		cin >> t;
		if(t==1){
			if(tt)tt=false;
			else tt=true;
		}else{
			int f;
			cin >> f;
			char p;
			cin >> p;
			if(f==1){
				if(!tt)s.insert(s.begin(),p);
				else s+=p;
			}else{
				if(!tt)s+=p;
				else s.insert(s.begin(),p);
			}
		}	
	}
	if(tt){
		reverse(s.begin(),s.end());
	}
	cout << s << endl;
	return 0;
}