#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <set>
using namespace std;

int n,m;
int main(void){
	set<string> id;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		string str;
		cin >> str;
		id.insert(str);
	}
	scanf("%d",&m);
	bool flag=false;
	for(int i=0;i<m;i++){
		string str;
		cin >> str;
		if(id.find(str)!=id.end()){
			if(!flag)cout << "Opened";
			else cout << "Closed";
			cout << " by " << str << endl;
			flag=!flag;
		}else{
			cout << "Unknown " << str << endl;
		}
	}
	return 0;
}