#include <iostream>
#include <algorithm>
using namespace std;
long long a[100010],sum = 0;
int main(){
	int i,j,n;
	cin >> n;
	for(i=0;i<n;i++){
		cin >> a[i];
		sum ^= a[i];
	}
	for(i=0;i<=60;i++){
		long long x = (1LL<<i);
		if(sum & x){
			for(j=0;j<n;j++){
				if(a[j]&x) a[j] ^= x;
			}
		}
	}
	int k = 0;
	for(i=60;i>=0;i--){
		int p = -1;
		long long x = (1LL<<i);
		for(j=k;j<n;j++){
			if(a[j] & x){
				p = j;
				break;
			}
		}
		if(p==-1) continue;
		swap(a[k],a[p]);
		for(j=k + 1;j<n;j++){
			if(a[j] & x) a[j] ^= a[k];
		}
		k++;
	}
	long long ans = 0;
	for(i=0;i<n;i++){
		if(ans<(ans^a[i])) ans ^= a[i];
	}
	ans *= 2;
	cout << ans + sum << endl;
}