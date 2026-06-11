#include <bits/stdc++.h>

using namespace std;

//typedef pair<int,int> P;
typedef long long ll; 

#define int ll

main(){
	int A,B,M;
	cin >> A >> B >> M;
	vector<int> a(A),b(B);
	for(int i=0;i<A;i++) cin >> a[i];
	for(int i=0;i<B;i++) cin >> b[i];

	int ans = 1e18;
	for(int i=0;i<M;i++){
		int x,y,c;
		cin >> x >> y >> c;
		ans = min(ans,a[x-1]+b[y-1]-c);
	}

	sort(a.begin(),a.end());
	sort(b.begin(),b.end());

	ans = min(ans, a[0]+b[0]);

	cout << ans << endl;

	return 0;
}