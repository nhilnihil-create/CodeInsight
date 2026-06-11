#include <bits/stdc++.h>
#define PI 3.141592653589793
#define rep(i,n) for (int i=0;i<(n);i++)
using namespace std;
using ll = long long;

int main(void){
	cin.tie(0);
	ios::sync_with_stdio(false);

	int N,M;
	int i,k;
	int digit,num;
	bool flag=false;
	int ans=0;

	cin >> N >> M;

	vector<int> gv(N);

	rep(i,M){
		cin >> digit;
		cin >> num;

		if((gv[digit-1]!=0 && gv[digit-1]!=num)) flag=true;
		if((digit-1==0 && num==0) && N!=1) flag=true;

		gv[digit-1]=num;
	}

	if(flag){
		cout << "-1" << endl;
		return 0;
	}

	if(gv[0]==0 && N!=1) gv[0]=1;
	rep(i,N) ans+=gv[i]*pow(10.0,(double)(N-1-i));
	
	cout << ans << endl;

	return 0;
}

