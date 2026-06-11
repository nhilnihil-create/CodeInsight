#include <cstdio>
#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

string user[256];
int n,m;

int check(string in){
	for(int i=0;i<n;i++) if(user[i] == in) return 1;
	return 0;
}
main(){
	string in;
	int i,j;
	int state = 0;
	cin >> n;
	for(i=0;i<n;i++) cin >> user[i];
	cin >> m;
	for(i=0;i<m;i++){
		cin >> in;
		if(check(in)) printf("%s by %s\n", state++%2 ? "Closed":"Opened", in.c_str());
		else printf("Unknown %s\n", in.c_str());
	}
}