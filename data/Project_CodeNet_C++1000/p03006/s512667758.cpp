#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int n,i,j,s=0;
	long long x[105],y[105];
	pair<long long,long long> dif[3000];
	cin >> n;
	if(n==1){
		cout << "1" << endl;
		return 0;
	}
	for(i=1;i<=n;i++) cin >> x[i] >> y[i];
	for(i=1;i<n;i++){
		for(j=i+1;j<=n;j++){
			long long a,b;
			a=x[j]-x[i];
			b=y[j]-y[i];
			if(a<=0){
				a=-a;
				b=-b;
			}
			if(a==0&&b<0) b=-b;
			dif[s]=make_pair(a,b);
			s++;
		}
	}
	sort(dif,dif+s);
	long long flag=1,max=1;
	for(i=1;i<s;i++){
		if(dif[i].first==dif[i-1].first&&dif[i].second==dif[i-1].second){
			flag++;
			if(max<flag) max=flag;
		} else {
			flag=1;
		}
	}
	cout << n-max << endl;
	return 0;
}
