#include <cstdio>
#include <vector>
using namespace std;

long long c;

void merge(int left, int mid, int right, vector<int>& A) {
	vector<int> L, R;
	int n1=mid-left;
	int n2=right-mid;
	int i,j,k;

	L.resize(n1+1);
	R.resize(n2+1);

	for(i=0; i<n1; ++i) {
		L[i]=A[left+i];
	}
	for(i=0; i<n2; ++i) {
		R[i]=A[mid+i];
	}
	i=j=0;
	L[n1]=1000000001;
	R[n2]=1000000001;
	for(k=left; k<right; ++k) {
		if(L[i]>R[j]) {
			c+=(long long)n1-(long long)i;
			A[k]=R[j];
			++j;
		} else {
			A[k]=L[i];
			++i;
		}
	}
	return;
}

void mergeSort(int left, int right, vector<int>& A) {
	if(left+1<right) {
		int mid=left+(right-left)/2;
		mergeSort(left,mid,A);
		mergeSort(mid,right,A);
		merge(left,mid,right,A);
	}
	return;
}

int main() {
	int n;
	vector<int> A;
	scanf("%d",&n);
	c=0;
	A.resize(n);
	for(int i=0; i<n; ++i) {
		scanf("%d",&A[i]);
	}
	mergeSort(0,n,A);
	printf("%lld\n",c);
	return 0;
}