#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

const int MAX = 1255;

int main(){
	int a,b;
	bool flag = true;
	cin >> a >> b;
	for(int i=0;i < MAX;++i){
		if(int(i*0.08) == a && int(i*0.1) == b){
			cout << i << endl;
			flag = false;
			break;
		}
	}
	if(flag){
		cout << -1 << endl;
	}
	return 0;
}
