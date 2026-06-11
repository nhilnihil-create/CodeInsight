#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define f first
#define s second
#define pb push_back

pair<int, int> t[800005];

void build(int a[], int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = {a[tl], tl};
    } else {
        int tm = (tl + tr) / 2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm+1, tr);
        if(t[2*v].f>t[2*v+1].f){
        	t[v]=t[2*v];
        }
        else{
        	t[v]=t[2*v+1];
        }
    }
}

pair<int, int> maxi(int v, int tl, int tr, int l, int r) {
    if (l > r) 
        return {0, 0};
    if (l == tl && r == tr) {
        return t[v];
    }
    int tm = (tl + tr) / 2;
    auto u1=maxi(v*2, tl, tm, l, min(r, tm));
    auto u2=maxi(v*2+1, tm+1, tr, max(l, tm+1), r);
    if(u1.f>u2.f){
    	return u1;
    }
    else{
    	return u2;
    }
}

void update(int v, int tl, int tr, int pos, int new_val) {
    if (tl == tr) {
        t[v] = {new_val, tl};
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v*2, tl, tm, pos, new_val);
        else
            update(v*2+1, tm+1, tr, pos, new_val);
        if(t[2*v].f>t[2*v+1].f){
        	t[v]=t[2*v];
        }
        else{
        	t[v]=t[2*v+1];
        }
    }
}

main() {
	int n;
	cin>>n;
	int a[n];
	int b[n];
	for(int i=0; i<n; i++){
		cin>>a[i];
	}
	for(int i=0; i<n; i++){
		cin>>b[i];
	}
	build(b, 1, 0, n-1);
	int num=0;
	while(1){
		auto u=maxi(1, 0, n-1, 0, n-1);
		if(u.f==0){
			cout<<num;
			return 0;
		}
		int ind=u.s;
		int ne=0;
		if(u.f==a[ind]){
			update(1, 0, n-1, ind, 0);
			continue;
		}
		if(ind==0){
			int red=b[1]+b[n-1];
			if(red+a[ind]>b[ind]){
				cout<<-1;
				return 0;
			}
			int times=(b[ind]-a[ind])/red;
			num+=times;
			ne=b[ind]-times*red;
		}
		
		else if(ind==n-1){
			int red=(b[0]+b[ind-1]);
			if(red+a[ind]>b[ind]){
				cout<<-1;
				return 0;
			}
			int times=(b[ind]-a[ind])/red;
			num+=times;
			ne=b[ind]-times*(red);
		}
		else{
			int red=b[ind-1]+b[ind+1];
			if(red+a[ind]>b[ind]){
				cout<<-1;
				return 0;
			}
			int times=(b[ind]-a[ind])/red;
			num+=times;
			ne=b[ind]-times*red;
		}
		if(ne<a[ind]){
			cout<<-1;
			return 0;
		}
		if(ne>a[ind]){
			update(1 , 0, n-1, ind, ne);
			b[ind]=ne;
			continue;
		}
		update(1, 0, n-1, ind, 0);
		b[ind]=ne;
	}
	return 0;
}