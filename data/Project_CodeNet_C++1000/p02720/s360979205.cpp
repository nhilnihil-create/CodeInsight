#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define int ll
#define endl "\n"

vector <int> lunlun;
int n;
int to_num(string number){
	int temp = 1;
	int ans = 0;
	
	for (int i=number.size()-1; i>=0; i--){
		ans += (number[i] - '0')*temp;
		temp *= 10;
	}
	
	return ans;
}

void generate(string now){
	if (now.size() == 11) return;
	lunlun.push_back(to_num(now));
	
	char this_ = now[(int)now.size()-1];
	if (this_ != '0'){
		this_--;
		generate(now + this_);
		this_++;
	}	
	
	if (this_ != '9'){
		this_++;
		generate(now + this_);
		this_--;
	} 
	
	generate(now + this_);
}

signed main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	
	for (int i=1; i<10; i++){
		generate(to_string(i));
	}
	sort(lunlun.begin(), lunlun.end());
	

	cin >> n;
//	for (int i=0; i<n; i++){
//		cout << lunlun[i] << endl;
//	}
	
	cout << lunlun[n-1] << endl;
	
	return 0;
}