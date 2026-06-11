#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define int long long int

main() {
	int x, y, a, b, c;
	cin>>x>>y>>a>>b>>c;
	vector<int>p;
	vector<int>q;
	vector<int>r;
	for(int i=0; i<a; i++){
		int x;
		cin>>x;
		p.pb(x);
	}
	for(int i=0; i<b; i++){
		int x;
		cin>>x;
		q.pb(x);
	}
	for(int i=0; i<c; i++){
		int x;
		cin>>x;
		r.pb(x);
	}
	sort(p.begin(), p.end());
	sort(q.begin(), q.end());
	sort(r.begin(), r.end());
	reverse(p.begin(), p.end());
	reverse(q.begin(), q.end());
	reverse(r.begin(), r.end());
	int p1=x-1;
	int p2=y-1;
	int ans=0;
	for(int i=0; i<=p1; i++){
		ans+=p[i];
	}
	for(int i=0; i<=p2; i++){
		ans+=q[i];
	}
	int p3=0;
	while(p3<c){
		if(p1>=0 && p2>=0){
			if(p[p1]>q[p2] && r[p3]>q[p2]){
				ans+=r[p3];
				ans-=q[p2];
				p2--;
				p3++;
				continue;
			}
			if(p[p1]<=q[p2] && r[p3]>p[p1]){
				ans+=r[p3];
				ans-=p[p1];
				p1--;
				p3++;
				continue;
			}
			break;
		}
		if(p1<0 && p2<0){
			break;
		}
		if(p1<0){
			if(q[p2]<r[p3]){
				ans+=r[p3];
				ans-=q[p2];
				p2--;
				p3++;
				continue;
			}
			break;
		}
		if(p2<0){
			if(p[p1]<r[p3]){
				ans+=r[p3];
				ans-=p[p1];
				p3++;
				p1--;
				continue;
			}
			break;
		}
	}
	cout<<ans;
	return 0;
}