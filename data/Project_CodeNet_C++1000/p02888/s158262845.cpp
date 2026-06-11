#include <iostream>
#include <algorithm>
typedef long long LL;
using namespace std;
const int N=2010;
int a[N];
int n;
LL ans;

int main(){
	cin>>n;
	for(int i=0;i<n;i++) cin>>a[i];
	
	sort(a,a+n);
	
	for(int i=0;i<n-1;i++)
		for(int j=i+1;j<n;j++){
			int x=a[i];
			int y=a[j];
			
			int minv=abs(x-y), maxv=x+y;
			int min_idx, max_idx;

			int l=0,r=n-1;
			while(l<r){
				int mid=l+r>>1;
				if(a[mid]>minv) r=mid;
				else l=mid+1;
			}
			min_idx=l;
			
			l=0,r=n-1;
			while(l<r){
				int mid=l+r+1>>1;
				if(a[mid]<maxv) l=mid;
				else r=mid-1;
			}
			max_idx=l;
			
			int k;
			if(max_idx<=min_idx || a[max_idx]>=maxv || a[min_idx]<=minv) k=0;
			else{
				k=max_idx-min_idx+1;
				if(i>=min_idx && i<=max_idx) k--;
				if(j>=min_idx && j<=max_idx) k--;
			}
			
			ans+=(LL)k;
		}
		
	cout<<ans/3;
	return 0;
}
