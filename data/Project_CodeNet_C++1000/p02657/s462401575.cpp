#include <bits/stdc++.h>
using namespace std;
#define	fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define loop(n,arr)  for(int i=0;i<n;i++)cin>>arr[i]; // 0 => n
#define	pi 3.14159265358979323846
#define	endl "\n"
#define f first
#define s second

typedef long long ll;
typedef unsigned long long ull;
const ll INF=1e18; 
const int N = 1e5+5 , oo=0x3f3f3f3f , mod=1e9+7;
void file(){freopen("out.txt","w",stdout);/*freopen("in.txt","r",stdin);*/}
int a[N];

int bs(int x,int n){
	int c=0,l=0,r=n-1;
	while(l<=r){
		int mid=(l+r)/2;
		if(a[mid]==x){
			c++;
			break;
		}
		else if(a[mid]<x){
			l=mid+1;
			c++;
		}
		else{
			r=mid-1;
			c++;
		}
	}
return c;
}


int main(){
	fast
	int x,y;
	cin>>x>>y;
	cout<<x*y;
	
	return 0;
}