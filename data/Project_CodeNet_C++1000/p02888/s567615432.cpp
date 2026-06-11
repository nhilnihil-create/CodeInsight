#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef tuple<int,int,int> tp;

int main(){
	int N;
	cin >> N;
	vector<int> L(N);
	for(int i=0; i<N; i++)cin >> L[i];
	sort(L.begin(),L.end());

	int ans = 0;
	for(int i=0; i<N; i++){
		for(int j=i+1; j<N; j++){
			int a = L[i],  b = L[j];
			int k = lower_bound(L.begin()+j,L.end(),a+b)-L.begin();
			ans += max(k-(j+1), 0);
		}
	}
	cout << ans << endl;
	return 0;
}

