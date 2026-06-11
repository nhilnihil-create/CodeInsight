#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <stack>

using namespace std;

int n;
vector<int> vec;
bool used[100005];

int main(void)
{
	cin >> n;
	
	int cnt = 0;
	for(int t = n; t; t/=2) cnt += t&1;
	if(cnt == 1){
		cout << "No" << endl;
		return 0;
	}
	
	int a;
	for(int i = 0; (1<<i) <= n; i++){
		a = 1<<i;
	}
	int b = n - a, p;
	
	
	int x = (n+1)/4-1;
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	
	
	if(n >= 7){
		int l = (n+1)/4;
		for(int j = 1; j < l; j++){
			if(n % 4 == 0 && j == a/4) continue;
			for(int i = 0; i < 4; i++) vec.push_back(4*j+i);
			for(int i = 0; i < 4; i++) vec.push_back(4*j+i);
		}
	}
	if(n % 4 == 0){
		for(int j = 0; j < vec.size(); j++){
			if(vec[j] == b){
				p = j;
				break;
			}
		}
		for(int i = 0; i < 4; i++) vec.insert(vec.begin()+p, (a+i));
		for(int i = 0; i < 4; i++) vec.insert(vec.begin()+p, (a+i));
	}
	
	//for(int i = 0; i < vec.size(); i++) cout << vec[i] << " "; cout << endl;
	
	
	cout << "Yes" << endl;
	if(n % 4 == 0){
		cout << b << " " << n << endl;
		cout << a << " " << 2*n << endl;
	}
	else{
		if(n % 4 < 3){
			int y = (n/4)*4;
			cout << 2 << " " << y << endl;
			cout << 3+n << " " << n+y+1 << endl;
			cout << y << " " << y+1 << endl;
			cout << n+y+1 << " " << n+y << endl;
			if(n % 4 == 2){
				cout << y << " " << y+2 << endl;
				cout << 2+n << " " << n+y+2 << endl;
			}
		}
	}
	for(int i = 0; i < vec.size(); i++){
		if(used[vec[i]]) vec[i] += n;
		else used[vec[i]] = true;
	}
	for(int i = 1; i < vec.size(); i++){
		cout << vec[i-1] << " " << vec[i] << endl;
	}
	
	return 0;
}