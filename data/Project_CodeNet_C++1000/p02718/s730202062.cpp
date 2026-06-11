#include <bits/stdc++.h>
 
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	long long int n,m;
	long long int sum=0;
	cin>>n>>m;
	vector<long long int> v;
	while(n--){
		long long int x;
		cin>>x;
		sum+=x;
		v.push_back(x);
	}
	long long int c=0;
	sort(v.begin(),v.end());
	for(long long int i=0;i<v.size();i++){
		if(v[i]>=(sum/(4*m))){
			c++;
		}
	}
	if(sum%(m*4)!=0){
		long long int d=(sum/(4*m));
		long long int dd=0;
		for(long long int i=0;i<v.size();i++){
			if(v[i]==d){
				dd++;
			}
		}
		c-=dd;
	}
	if(c>=m){
		cout<<"Yes";
	}
	else{
		cout<<"No";
	}
	return 0;
}