#include <bits/stdc++.h>
#define INF 1e10
using namespace std;
typedef long long llong;
int A[200000];

llong merge(int left,int mid,int right)
{
	int n1=mid-left,n2=right-mid;
	int L[n1+1],R[n2+1];
	for(int i=0;i<n1;i++) L[i] = A[left+i];
	for(int i=0;i<n2;i++) R[i] = A[mid+i];
	L[n1] = R[n2] = INF;
	llong ans=0; 
	int i=0,j=0;
	for(int k=left;k<right;k++)
		if(L[i]>R[j]) 
			A[k] = R[j++], ans += n1-i;
		else A[k] = L[i++];
	return ans;
}
llong mergeSort(int left,int right)
{
	if(left+1<right){
		int mid = (left+right)/2;
		llong n1,n2;
		n1 = mergeSort(left,mid);
		n2 = mergeSort(mid,right);
		return n1+n2+merge(left,mid,right);
	}
	return 0;
}
int main(){
	
	int n; cin>>n;
	for(int i=0;i<n;i++) scanf("%d",&A[i]);
	cout<<mergeSort(0,n)<<endl;
	return 0;
}
