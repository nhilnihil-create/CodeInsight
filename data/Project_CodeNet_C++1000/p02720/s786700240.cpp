#include <bits/stdc++.h>
using namespace std;

#define int long long
#define forn(i,a,n) for (int i=a; i<n; i++)

signed main(){
	ios::sync_with_stdio(false);
   	cin.tie(0);

	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);

	int k;
	cin>>k;
	queue<int> q;
	forn(i,1,10) q.push(i);
	while (--k){
		int x=q.front();
		q.pop();
		int y=x%10;
		forn(i,y-1,y+2){
			if (i<0 || i>=10) continue;
			q.push(x*10+i);
		}
	}
	cout<<q.front()<<endl;
	return 0;
}