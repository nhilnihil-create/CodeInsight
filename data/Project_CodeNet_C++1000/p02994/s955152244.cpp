#include<iostream>
#include<algorithm>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n,a;
	cin >> n >> a;
	
	int eat;
	int l = a;
	int r = a+n-1;

	if(r<=0) eat=r;
	else if(l>=0) eat=l;
	else eat=0; 
	
	int answer=(r+l)*(r-l+1)/2-eat;
	cout << answer;

	return 0;
}