#include <bits/stdc++.h>
using namespace std;

vector<int> forintinput(int n) {
	vector<int> x;
	for(int i = 0;i < n;i++){
		int ia;
		cin >> ia;
		x.push_back(ia);
	}
	return x;
}
int main(){
	int n;
	cin >> n;
	vector<unsigned long long> a(n);
	for(int i = 0;i < n;i++){
		cin >> a[i];
	}
	unsigned long long cnt = 1;
	sort(a.begin(), a.end());
	if(a[0] <= 0){
		cout << 0 << endl;
	}else{
		for(int i = 0;i < n;i++){
			if(a[i] <= 1000000000000000000/cnt){
				cnt = cnt * a[i];
			}else{
				cout << -1 << endl;
				goto owari;
			}
		}
		cout << cnt << endl;
	}
	owari:
	return 0;
}