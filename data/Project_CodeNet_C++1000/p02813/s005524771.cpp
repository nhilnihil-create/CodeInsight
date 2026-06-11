#include <bits/stdc++.h>
#define boost_io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define num(a) a-'0'
#define maxself(a,b) if(b>a)a=b
#define minself(a,b) if(b<a)a=b;
#define debug(x) cout<<#x<<":"<<x<<" "
#define all(a) (a).begin(), (a).end()
#define vi vector<int>
#define vl vector<long long int>
#define pb push_back
#define mk make_pair
#define f first
#define s second
#define ln "\n"	
typedef long long int ll;
typedef long double ld;
typedef double d;
using namespace std;
ll modF=1e9+7;
ll INF=1e11;

int chkPerm(int a[],int n,int h[],int counter){
	int pos=1;
	for(int i=0;i<n;i++){
		if(a[i]!=h[i])
			pos=0;
	}
	if(pos){
		return counter;
	}
	else{
		for(int i=n-2;i>=0;i--){
			if(h[i]<h[i+1]){
				int ind;
				for(int j=i+1;j<n;j++){
					if(h[i]<h[j]){
						ind = j;
					}
					else{
						break;
					}
				}
				int swap=h[i];
				h[i]=h[ind];
				h[ind]=swap;
				sort(h+i+1,h+n);
				break;
			}
		}
		return chkPerm(a,n,h,counter+1);
	}
}

void solve(){
	int n;
	cin>>n;
	int p[n];
	int q[n];
	for(int i=0;i<n;i++){
		cin>>p[i];
	}
	for(int i=0;i<n;i++){
		cin>>q[i];
	}
	int h[n];
	for(int i=1;i<=n;i++){
		h[i-1]=i;	
	}
	int cp=chkPerm(p,n,h,1);
	sort(h,h+n);
	int cq=chkPerm(q,n,h,1);
	cout<<abs(cp-cq)<<ln;
}

int main(){
	boost_io;
	solve();
	return 0;
}