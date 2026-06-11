#include <bits/stdc++.h>
using namespace std;

vector<int> forintinput(int n) {
	vector<int> x(100000);
	for(int i = 0;i < n;i++) cin >> x[i];
	return x;
}
int main(){
	int n,m;
	cin >> n >> m;
	vector<int> s(m);
	vector<char> c(m);
	for(int i = 0;i < m;i++){
		cin >> s[i] >> c[i];
	}
	if(n == 1){
		for(int i = 0;i < pow(10,n);i++){
			string u = to_string(i);
			int cnt = 0;
			for(int i = 0;i < m;i++){
				if(u[s[i]-1] != c[i]){
					cnt++;
				}
			}
			if(i == pow(10,n)-1 && cnt != 0){
				cout << -1 << endl;
				break;
			}
			if(cnt != 0){
				continue;
			}else{
				cout << i << endl;
				break;
			}
		}
	}else{
		for(int i = pow(10,(n-1));i < pow(10,n);i++){
			string u = to_string(i);
			int cnt = 0;
			for(int i = 0;i < m;i++){
				if(u[s[i]-1] != c[i]){
					cnt++;
				}
			}
			if(i == pow(10,n)-1 && cnt != 0){
				cout << -1 << endl;
				break;
			}
			if(cnt != 0){
				continue;
			}else{
				cout << i << endl;
				break;
			}
		}
	}
}