#include <iostream>


using namespace std;

int main(){
	int n,r;
	while(cin >> n >> r,n){
		int ds[n];
		for(int i = 0;i < n;i++) ds[i] = n - i;
		int p,c;
		for(int i = 0;i < r;i++){
			cin >> p >> c;
			int sds[n];
			p--;
			for(int t = p;t < p + c;t++) sds[t-p] = ds[t];
			for(int t = 0;t < p;t++) sds[t+c] = ds[t];
			for(int t = 0;t < p + c;t++) ds[t] = sds[t];
		}
		cout << ds[0] << endl;
	}
}