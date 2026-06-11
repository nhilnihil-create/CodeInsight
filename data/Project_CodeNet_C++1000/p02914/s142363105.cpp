#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1e5;

inline bool cek_bit(ll mask, int x){
	return mask&(1ll<<x);
}

int n;
ll li[N+5];

int depan[65];
int urut = 0;
int matrix[65][N+5];

bool masuk(int bit){
	urut++;
	for(int i=1;i<=n;i++){
		if(cek_bit(li[i],bit)){
			matrix[urut][i] = 1;
		} else {
			matrix[urut][i] = 0;
		}
	}
	matrix[urut][n+1] = 1;
	for(int i=1;i<urut;i++){
		if(matrix[urut][depan[i]] == 1){
			for(int j=1;j<=n+1;j++){
				matrix[urut][j]^=matrix[i][j];
			}
		}
	}
	int awal = -1;
	for(int i=1;i<=n;i++){
		if(matrix[urut][i] == 1){
			awal = i;
			break;
		}
	}
	if(awal == -1 && matrix[urut][n+1] == 0){
		urut--;
		return 1;
	} else if(awal == -1 && matrix[urut][n+1] == 1){
		urut--;
		return 0;
	}
	depan[urut] = awal;
	return 1;
}

int main(){
	scanf("%d",&n);
	ll ans = 0ll;
	for(int i=1;i<=n;i++){
		scanf("%lld",&li[i]);
	}
	for(int i=59;i>=0;i--){
		int cnt = 0;
		for(int j=1;j<=n;j++){
			if(cek_bit(li[j],i)){
				cnt++;
			}
		}
		if(cnt&1){
			ans+=(1ll<<i);
		} else {
			if(masuk(i)){
				ans+=(1ll<<(i+1));
			}
		}
	}
	printf("%lld\n",ans);
	return 0;
}
