#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	long long int n,x,l;
	cin>>n>>x;
	vector<long long int> v;
	while(n--){
		cin>>l;
		v.push_back(l);
	}
	long long int c=0,temp=0;
	for(long long int i=0;i<v.size();i++){
		temp+=v[i];
		if(temp<=x){
			c++;
		}
	}
	cout<<c+1;
	return 0;
}