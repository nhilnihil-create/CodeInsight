#include<bits/stdc++.h>
using namespace std;
#define LL long long

int main(){
	// sengen
	int n;
	// nyuryoku
	cin >> n;
	int p[n],q[n];
	for(int i=0;i<n;i++){
		cin >> p[i];
		q[i] = p[i];
	}
	string ans = "NO";
	// keisan
	sort(q,q+n);
	for(int i=0;i<n;i++){
		if(p[i] != q[i]){
			break;
		}
		if(i == n-1){
			ans = "YES";
		}
	}
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			for(int k=0;k<n;k++){
				int tmp;
				tmp = k;
				if(k == i){
					tmp = j;
				}
				if(k == j){
					tmp = i;
				}
				if(q[k] != p[tmp]){
					break;
				}
				if(k == n-1){
					ans = "YES";
				}
			}
		}
	}
	// syutsuryoku
	cout << ans << endl;
}