#include<bits/stdc++.h>
using namespace std;
typedef pair<double,double> pi;
pi arr[10];
double sqr(double a){
	return a*a;
}
double fac(int n){
	int ret = 1;
	for(int i=1; i<=n; i++) ret*=i;
	return (double)ret;
}
int main(){
	int n;
	cin>>n;
	for(int i=1; i<=n; i++) cin>>arr[i].first>>arr[i].second;
	vector<int>order;
	for(int i=1; i<=n; i++) order.push_back(i);
	double ret = 0;
	do{
		for(int i=1; i<order.size(); i++){
			int previ = order[i-1];
			int curr = order[i];
			double d = sqr(arr[previ].first-arr[curr].first);
			d+=sqr(arr[previ].second-arr[curr].second);
			ret+=sqrt(d);
		}
	}while(next_permutation(order.begin(),order.end()));
	cout.precision(10);
	cout<<ret/fac(n);
}