#include <iostream>

using namespace std;

int N;
int tama[11];

bool dfs(int x, int l, int r){
	if(x==10) 	return true;
	if(tama[x]>l)	dfs(x+1,tama[x],r);
	else if(tama[x]>r) dfs(x+1,l,tama[x]);
	else return false;
}

int main(){
	cin >> N;
	while(N--){
		for(int i=0;i<10;i++)
			cin >> tama[i];
		if(dfs(0,0,0))	cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}