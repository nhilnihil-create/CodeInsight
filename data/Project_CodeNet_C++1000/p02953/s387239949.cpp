#include <iostream>
#include <vector>
#define rep(i, n) for(int i = 0;i < n; i++)

using namespace std;

int main(){
	int n;
	cin >> n;
	vector<int> h(n);
	
	bool ans = true;
	
	rep(i, n){
		cin >> h.at(i);
	}
	
	for(int i = 1; i < n; i++){
		if(h.at(i) - 1 >= h.at(i-1)) h.at(i) -= 1;
		if(h.at(i) < h.at(i-1)) ans = false;
	}
	
	if(ans)cout << "Yes";
	else cout << "No";
	cout << endl;
	
}