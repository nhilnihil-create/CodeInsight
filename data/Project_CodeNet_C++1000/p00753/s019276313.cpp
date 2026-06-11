#include<iostream>
#include<vector>

using namespace std;

vector<int> ans;
bool isP(int num);

int main(){
	while(1){
		int n;
		cin >> n;
		if(n == 0) break;
		int count = 0;
		for(int i = n+1;i <= 2*n;i++){
			if(isP(i)) count++;
		}
		ans.push_back(count);
	}
	for(int i = 0;i < ans.size();i++) cout << ans[i] << endl;
	
	return 0;
}

bool isP(int num){
	bool p = true;
	
	for(int i = 2; i < num;i++){
		if(num > 5 && i*i > num) break;
		if(num % i == 0){p = false;break;}
	}
	
	return p;
}