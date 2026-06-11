#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using LL = long long;
using P = pair<int,int>;


int main(){
	int N;cin >> N;
	vector<double> v(N);
	rep(i,N) cin >> v[i];
	sort(v.begin(),v.end());
	double sum = v[0];
	rep(i,N-1){
		sum = (sum + v[i+1])/2;
	}
	printf("%.10lf\n",sum);

}












