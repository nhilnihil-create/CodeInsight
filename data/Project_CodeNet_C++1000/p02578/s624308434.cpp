# include <bits/stdc++.h>
using namespace std;
long long t, a, cnt, bnt;
vector <int> vc;
int main(){
	cin >> t;
	for (int i = 0; i < t; i ++){
		cin >> a;
		vc.push_back(a);
	}
	for (int i = 1; i < t; i ++){
		if (vc[i] < vc[i -1]){
            cnt = vc[i - 1] - vc[i];
            vc[i] += cnt;
            bnt += cnt;
		}
	}
	cout << bnt;
}
