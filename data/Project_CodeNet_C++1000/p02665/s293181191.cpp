#include<iostream>
#include<vector>
#include<algorithm>

typedef long long ll;

int main(){
	int n;
	std::cin >> n;
	std::vector<ll> a(n+1);
	for(int i=0; i<=n; i++){
		std::cin >> a[i];
	}
	// 下から頂点数の上界を求める
	std::vector<ll>  up(n+1);
	std::vector<ll> error(n+1);
	up[n] = a[n];
	error[n] = a[n];
	//std::cout << "error[n]: " << error[n] << std::endl;
	for(int i=n-1; i>=0; i--){
		up[i] = up[i+1] + a[i];
		error[i] = (error[i+1] + 1)/2 + a[i];
		//std::cout << error[i] << std::endl;
	}
	if(error[0] > 1){
		std::cout << -1 << std::endl;
		return 0;
	}
	//上から頂点数の上界を求める
	std::vector<ll> down(n+1);
	ll res = 0;
	down[0] = 1;
	for(int i=1; i<=n; i++){
		down[i] = std::min(down[i-1]*2, up[i]);
		res += down[i];
		down[i] -= a[i];
	}
	res += 1;
	std::cout << res << std::endl;
	return 0;
}