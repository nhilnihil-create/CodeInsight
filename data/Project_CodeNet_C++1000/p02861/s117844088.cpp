#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define io ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
vector<pair<int, int>> arr;
int n;
double calDis(pair<int, int> a, pair<int, int> b){
	return sqrt(pow((a.first - b.first), 2) + pow((a.second - b.second), 2));
}
double solve1(int arr1[]){
	double res = 0;
	for(int i = 1; i < n; i++){
		res += calDis(arr[arr1[i - 1]], arr[arr1[i]]);
	}
	//cout<<res<<endl;
	return res;
}
void solve(){
	cin>>n;
	arr.resize(n);
	for(int i = 0; i < n; i++){
		int x, y;
		cin>>x>>y;
		arr[i] = {x, y};
	}
	int arr1[n];
	for(int i = 0; i < n; ++i) arr1[i] = i;
	double fact = 1;
	for(int i = 2; i <= n; ++i) fact *= i;
	//cout<<fact<<endl;
	double sum = 0;
	sum += solve1(arr1);
	//cout<<sum<<endl;
	while(next_permutation(arr1, arr1 + n)){
		sum += solve1(arr1);
	}
	//sum += solve1(arr);
	//cout<<sum<<endl;
	cout<<setprecision(20)<<sum / fact;
}
int main(){
	io;
	solve();
	return 0;
}
