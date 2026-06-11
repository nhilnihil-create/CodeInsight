#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define f first
#define s second
#define pb push_back
pair<int, int> t[400010];
int arr[100005];
void build(int a[], int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = {a[tl], tl};
    } else {
        int tm = (tl + tr) / 2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm+1, tr);
        if(t[2*v].f>t[2*v+1].f){
        	t[v]=t[2*v+1];
        }
        else{
        	t[v]=t[2*v];
        }
    }
}

pair<int, int> mini(int v, int tl, int tr, int l, int r) {
    if (l > r) 
        return {2, 0};
    if (l == tl && r == tr) {
        return t[v];
    }
    int tm = (tl + tr) / 2;
    auto u1=mini(v*2, tl, tm, l, min(r, tm));
    auto u2=mini(v*2+1, tm+1, tr, max(l, tm+1), r);
    if(u1.f>u2.f){
    	return u2;
    }
    else{
    	return u1;
    }
}


main() {
	int n, m;
	cin>>n>>m;
	string s;
	cin>>s;
	int arr[n+1];
	for(int i=0; i<=n; i++){
		arr[i]=(s[i]-'0');
	}
	build(arr, 1, 0, n);
	int pos=n;
	vector<int>ans;
	ans.pb(n);
	while(1){
		int fir=max(0LL, pos-m);
		int sec=max(0LL, pos-1);
		auto u=mini(1, 0, n, fir, sec);
		if(u.f==1){
			cout<<-1;
			return 0;
		}
		int node=u.s;
		ans.pb(node);
		pos=node;
		if(node==0){
			break;
		}
	}
	reverse(ans.begin(), ans.end());
	for(int i=0; i<ans.size()-1; i++){
		cout<<ans[i+1]-ans[i]<<" ";
	}
	return 0;
}