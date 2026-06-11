#include<iostream>
#include<algorithm>
using namespace std;
#define Max 500001
void maxheapify(int a[],int i,int h){
int r,l,largest,k;
	l=i*2;r=i*2+1;
	if(l<=h&&a[l]>a[i])
	 largest=l;
	else
	 largest=i;
	if(r<=h&&a[r]>a[largest])
	 largest=r;
	if(largest!=i){
	    k=a[i];
		a[i]=a[largest];
		a[largest]=k;
		maxheapify(a,largest,h);
	}
}
void buildmaxheap(int a[],int h){
int i;
for(i=h/2;i>0;i--)
maxheapify(a,i,h);
}
main(){
int h,i,a[Max];
	scanf("%d",&h);
	for(i=1;i<=h;i++)
	scanf("%d",&a[i]);
	buildmaxheap(a,h);
	for(i=1;i<=h;i++)
	printf(" %d",a[i]);
	printf("\n");
	return 0;
}

