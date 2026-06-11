#include<bits/stdc++.h>
using namespace std;

// num[i]...iが書かれているカードの数
// num2[i]..i枚ある数字の個数
// num2_sum[i]..i枚以下ある数字の個数
// f[i].....i回操作を行える、Kの最大値

int N, num[300001], num2[300001], num2_sum[300001];
vector<int> f(300001);

int main(){
	cin >> N;
	for(int i=0; i<N; i++){
		int a; cin >> a;
		num[a]++;
	}
	for(int i=0; i<=N; i++) num2[num[i]]++;
	num2_sum[0] = num2[0];
	for(int i=1; i<=N; i++){
		num2_sum[i] = num2_sum[i-1] + num2[i];
	}
	int sum = 0;
	for(int i=0; i<=N; i++){
		sum += min(num[i], 1);
	}
	f[0] = -1e9;
	f[1] = sum;
	f[1] *= -1;
	for(int i=2; i<=N; i++){
		sum = sum + num2[i] + (num2_sum[N] - num2_sum[i]);
		f[i] = sum/i;
		f[i] *= -1;
	}
	for(int i=1; i<=N; i++){
		int ans = lower_bound(f.begin(), f.end(), -i+1) - f.begin();
		cout << ans - 1 << endl;
	}
	return 0;
}