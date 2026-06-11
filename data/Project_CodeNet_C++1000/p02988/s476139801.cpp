#include <bits/stdc++.h>
 
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	long long int n;
	cin>>n;
	vector<long long int> p;
	while(n--){
		long long int x;
		cin>>x;
		p.push_back(x);
	}
	long long int c=0;
	for(long long int i=1;i<p.size()-1;i++){
		if(p[i]<max(p[i],max(p[i-1],p[i+1]))&&p[i]>min(p[i],min(p[i+1],p[i-1]))){
			c++;
		}
	}
	cout<<c;
	return 0;
}