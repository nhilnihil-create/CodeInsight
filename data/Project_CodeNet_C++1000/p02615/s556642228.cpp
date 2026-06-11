#include <iostream>
#include <vector>
using namespace std;
const int max_num=200001;
vector<int> G;

void swap(long long int v[],int i,int j){
	long long int temp=v[i];
	v[i]=v[j];
	v[j]=temp;
}

void qsort(long long int v[],int left,int right){
	int i,last;

	if(left>=right)
		return;
	swap(v,left,(left+right)/2);
	last=left;
	for(i=left+1;i<=right;i++)
		if(v[i]>v[left])
			swap(v,++last,i);
	swap(v,left,last);
	qsort(v,left,last-1);
	qsort(v,last+1,right);
}

void insSort(long long int *a,int n, int g){
	int v,j;
	for(int i=g;i<n;i++){
		v=a[i];
		j=i-g;
		while(j>=0 && a[j]<v){
			a[j+g]=a[j];
			j=j-g;
			a[j+g]=v;
		}
	}
}

void shellSort(long long int *a,int n){
	for(int h=1;;){
		if(h>n)
			break;
		G.push_back(h);
		h=3*h+1;
	}
	for(int i=G.size()-1;i>=0;i--)
		insSort(a,n,G[i]);

}



void inputnumbers(int *n,long long int *a){
	cin >> *n;
	for(int i=0;i<*n;i++)
		cin >> *(a+i);
}

void printnumbers(int n,long long int *a){
	for(int i=0;i<n;i++)
		cout << *(a+i) << ' ';
	cout << endl;
}



long long int solve(int n,long long int a[]){
	int q=n/2;
	int r=n%2;

	//qsort(a,0,n-1);
	shellSort(a,n);

	//printnumbers(n,a);

	long long int sum=a[0];
	for(int i=1;i<q;i++)
		sum+=2*a[i];
	if(r==1)
		sum+=a[q];

	return sum;
}

int main() {
	long long int a[max_num];
	int n;

	inputnumbers(&n,a);

	//printnumbers(n,a);
	//qsort(a,0,n-1);
	//printnumbers(n,a);


	cout << solve(n,a) << endl;

	return 0;
}
