#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> P;
typedef long long ll; 

#define int ll

const ll mod = 1e9 + 7;

int a[3][3];
int n;
bool ok[9];

main(){
	for(int i=0;i<9;i++){
		cin >> a[i/3][i%3];
		ok[i] = false;
	}

	cin >> n;
	for(int i=0;i<n;i++){
		int b;
		cin >> b;
		for(int j=0;j<9;j++){
			if(a[j/3][j%3]==b) ok[j] = true;
		}
	}

	if(ok[0]&&ok[1]&&ok[2]){
		cout << "Yes" << endl;
	}else if(ok[3]&&ok[4]&&ok[5]){
		cout << "Yes" << endl;
	}else if(ok[6]&&ok[7]&&ok[8]){
		cout << "Yes" << endl;
	}else if(ok[0]&&ok[3]&&ok[6]){
		cout << "Yes" << endl;
	}else if(ok[1]&&ok[4]&&ok[7]){
		cout << "Yes" << endl;
	}else if(ok[2]&&ok[5]&&ok[8]){
		cout << "Yes" << endl;
	}else if(ok[0]&&ok[4]&&ok[8]){
		cout << "Yes" << endl;
	}else if(ok[2]&&ok[4]&&ok[6]){
		cout << "Yes" << endl;
	}else{
		cout << "No" << endl;
	}
	

	return 0;
}
