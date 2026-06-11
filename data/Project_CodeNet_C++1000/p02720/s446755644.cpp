#include <bits/stdc++.h>

using namespace std;

//typedef pair<int,int> P;
typedef long long ll; 

#define int ll


main(){
	int k;
	cin >> k;

	queue<ll> q;
	for(int i=1;i<=9;i++) q.push(i);
	int ans;
	for(int i=0;i<k;i++){
		ll t = q.front();
		if(i==k-1) ans = t;
		q.pop();
		if(t%10!=0) q.push(10*t+(t%10)-1);
		q.push(10*t+(t%10));
		if(t%10!=9) q.push(10*t+(t%10)+1);
	}

	cout << ans << endl;

	return 0;
}