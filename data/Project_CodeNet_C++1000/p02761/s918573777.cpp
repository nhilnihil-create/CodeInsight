#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
	int n,m;
	cin >> n >> m;
	vector<int> num(5,-1);
	for(int i=0;i<m;i++){
		int s;
		cin >> s;
		int c;
		cin >> c;
		if(num[s] != -1 && num[s] != c){
			cout << -1 << endl;
			return 0;
		}
		num[s] = c;
	}
	int ans = 0;
	if(n == 3){
		for(int i=1;i<n+1;i++){
			if(i==1 && num[i] == 0){
				cout << -1 << endl;
				return 0;
			}
			if(i==1 && num[i] == -1){
				num[1] = 1;
			}
			if(i!=1 && num[i] == -1){
				num[i] = 0;
			}
			if(i==1) ans += num[1] * 100;
			if(i==2) ans += num[2] * 10;
			if(i==3) ans += num[3];
		}
	}else if(n == 2){
		if(num[1] == 0){
			cout << -1 << endl;
			return 0;
		}
		if(num[1] == -1){
			num[1] = 1;
		}
		if(num[2] == -1){
			num[2] = 0;
		}
		ans += num[1] * 10;
		ans += num[2];
	}else{
		if(num[1] == -1){
			cout << 0 << endl;
		}else{
			cout << num[1] << endl;
		}
		return 0;
	}
	cout << ans << endl;
	return 0;
}
