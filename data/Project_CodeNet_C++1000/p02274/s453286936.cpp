#include<iostream>
#include<algorithm>
#define inf 1000000001
using namespace std;

long long merge(int a[],int left,int mid,int right){
int n1=mid-left,n2=right-mid;
	int L[n1+1],R[n2+1];
	int i,j,k;
	long long cnt=0;
	for(i=0;i<n1;i++)
	L[i]=a[left+i];
	for(j=0;j<n2;j++)
	R[j]=a[mid+j];
	L[n1]=R[n2]=inf;
	
	i=j=0;
	for(k=left;k<right;k++){
		if(L[i]<=R[j]){
		a[k]=L[i];
			
			i++;
		}
		else {
		a[k]=R[j];
			cnt+=n1-i;
			j++;
		}
	}
	return cnt;
}
long long mergesort(int a[],int left,int right){
	if(left+1<right){
		int mid=(left+right)/2;
		long long v1,v2,v3;
		v1=mergesort(a,left,mid);
		v2=mergesort(a,mid,right);
		v3=merge(a,left,mid,right);
		return v1+v2+v3;
	}
	else return 0;
}

main(){
	int n,a[200000];
	cin>>n;
	for(int i=0;i<n;i++)
	cin>>a[i];
	cout<<mergesort(a,0,n)<<endl;
	return 0;
}

