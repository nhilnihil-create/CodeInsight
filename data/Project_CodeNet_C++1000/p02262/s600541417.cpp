#include <cstdio>
#include <vector>
using namespace std;

int cnt,m;
vector<int> G;

void insertionSort(vector<int>& a, int n, int g) {
	for(int i=g; i<n; ++i) {
		int j,v=a[i];
		for(j=i-g; j>=0 && a[j]>v;j-=g) {
			swap(a[j+g],a[j]);
			++cnt;
		}
		a[j+g]=v;
	}
}

void shellSort(vector<int>& a,int n) {
	cnt = 0;
	m=0;
	int d=n;
	G.resize(n);
	while(1) {
		d=2*d/3;
		if(d<2) {
			G[m]=d;
			++m;
			break;
		}
		G[m]=d;
		++m;
	}
	for(int i=0; i<m; ++i) {
		insertionSort(a, n, G[i]);
	}
}

int main() {
	int n;
	vector<int> a;
	scanf("%d",&n);
	a.resize(n);
	for(int i=0; i<n; ++i) {
		scanf("%d",&a[i]);
	}
	shellSort(a,n);
	printf("%d\n",m);
	for(int i=0; i<m-1; ++i) {
		printf("%d ",G[i]);
	}
	printf("%d\n%d\n",G[m-1],cnt);
	for(int i=0;i<n;++i) {
		printf("%d\n",a[i]);
	}
	return 0;
}