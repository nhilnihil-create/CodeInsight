#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N=1e5+10;

int n,m,v,p;
int a[N];

bool check(int mid){
	ll ans=0;
	if(a[mid]+m<a[p]) return false;
	for(int i=1;i<=n;i++){
		if(i>=p&&i<mid) ans+=(ll)(a[mid]+m-a[i]);
		else ans+=(ll)m;
	}
//	cout<<' '<<ans<<endl; 
	if((ll)m*(ll)v>ans) return false;
	return true;
}

bool cmp(int a,int b){
	return a>b;
}

int main(){
	cin.tie(0);
	cin>>n>>m>>v>>p;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1,cmp);
	int l=1,r=n;
	while(l<r){
		int mid=(l+r+1)>>1;
		if(mid<=p) l=mid;
		else if(check(mid)) l=mid;
		else r=mid-1;
//		cout<<l<<' '<<r<<' ';
//		cout<<check(mid)<<endl;
	}
	cout<<l<<endl;
	return 0;
}
/*
	while(r>=l){
        mid=(r+l)>>1;
       // cout << "*******" << '\n';
        ll z=check(mid);
        if(z<m)
        r=mid-1;
        else{
            l=mid+1;
        }
    }
*/