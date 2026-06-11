#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector <int> n;

int main(){
	long long n,k,ans;
	cin>>n>>k;
	ans=n;
	if(n>k){
		n=n-n/k*k;
	}
	cout<<min(n,k-n)<<endl;
	return 0;
}
