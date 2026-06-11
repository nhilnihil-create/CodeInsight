#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
#define ld long double
#define pii pair<int,int>
#define fi first
#define se second
#define mex 1000005
#define fast  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
//vector<int> adj[mex];
//a+b=a^b+2*(a&b)
int t[mex];

void update(int v, int tl, int tr, int l, int r, int add) {
    if (l > r)
        return;
    if (l == tl && r == tr) {
        t[v] += add;
    } else {
        int tm = (tl + tr) / 2;
        update(v*2+1, tl, tm, l, min(r, tm), add);
        update(v*2+2, tm+1, tr, max(l, tm+1), r, add);
    }
}

int get(int v, int tl, int tr, int pos) {
    if (tl == tr)
        return t[v];
    int tm = (tl + tr) / 2;
    if (pos <= tm)
        return t[v] + get(v*2+1, tl, tm, pos);
    else
        return t[v] + get(v*2+2, tm+1, tr, pos);
}
int main(){
	fast
	int n,k;
	cin>>n>>k;
	int a[n];
	for(int i=0;i<n;i++)
	 cin>>a[i];
	
	while(k--){
		memset(t,0,sizeof(t));
		for(int i=0;i<n;i++){
		 update(0,0,n-1,max(0,i-a[i]),min(n-1,i+a[i]),1);
		 //cout<<max(0,i-a[i])<<" "<<min(n-1,i+a[i])<<endl;
	    }
		int b[n];
		for(int i=0;i<n;i++)
		 b[i]=get(0,0,n-1,i);
		
		int q=0;
		for(int i=0;i<n;i++){
			if(a[i]!=b[i]){
				q=1;
				break;
			}
		}
		if(q==0)
		 break;
		for(int i=0;i<n;i++)
		 a[i]=b[i];
	 }
	 for(int i=0;i<n;i++)
	  cout<<a[i]<<" ";
	      
				   	 
}
