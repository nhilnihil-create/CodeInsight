#include <iostream>
#include <string>
#include <queue>
#define llint long long

using namespace std;

llint n;
llint a[100005];

void GaussianElimination(llint a[], int n)
{
	llint r = 0;
	for(int i = 59; i >= 0 && r < n; i--){
		if((a[r]&(1LL<<i)) == 0){
			int p = -1;
			for(int j = r+1; j < n; j++){
				if(a[j] & (1LL<<i)){
					p = j;
					break;
				}
			}
			if(p == -1) goto end;
			swap(a[r], a[p]);
		}
		for(int j = 0; j < n; j++){
			if(j == r) continue;
			if(a[j]&(1LL<<i)) a[j] ^= a[r];
		}
		r++;
		end:;
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for(int i = 0; i < n; i++) cin >> a[i];
	
	llint ans = 0;
	for(int i = 0; i < 60; i++){
		llint cnt = 0;
		for(int j = 0; j < n; j++) if(a[j] & (1LL<<i)) cnt++;
		if(cnt % 2){
			ans += (1LL<<i);
			for(int j = 0; j < n; j++) a[j] &= ~(1LL<<i);
		}
	}
	
	/*for(int i = 0; i < n; i++){
		for(int j = 20; j >= 0; j--){
			cout << ((a[i]>>j)&1);
		}
		cout << endl;
	}
	cout << endl;*/
	
	GaussianElimination(a, n);
	
	/*for(int i = 0; i < n; i++){
		for(int j = 20; j >= 0; j--){
			cout << ((a[i]>>j)&1);
		}
		cout << endl;
	}*/
	
	llint tmp = 0, pre = 0;
	for(int i = 59; i >= 0; i--){
		if(tmp & (1LL<<i)) continue;
		for(int j = pre; j < n; j++){
			for(int k = 59; k >= i+1; k--){
				if(a[j] & (1LL<<k)) goto pass;
			}
			if(a[j] & (1LL<<i)) tmp ^= a[j], pre = j;
			break;
			pass:;
		}
	}
	//cout << tmp << endl;
	ans += tmp * 2;
	cout << ans << endl;
	
	return 0;
}