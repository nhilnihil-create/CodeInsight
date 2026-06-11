#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin >> n;
	vector<int> v(n+1,-1);
	int l=0;
	for(int i=0;i<n;i++){
		int a;
		cin >> a;
		if(v[l] < a){
			v[l+1]=a;
			l++;
		} else {
			*lower_bound(v.begin(),v.begin() + l,a) = a;
		}
	}
	cout << l << endl;
	
	return 0;
}