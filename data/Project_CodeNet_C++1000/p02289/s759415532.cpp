#include<iostream>
#include<algorithm>
#include<string>
#define INF 2434243
using namespace std;

int h=0;
void maxheap(int a[],int i){
int l,r,largest,ke;
	l=i*2;r=l+1;
	if(l<=h && a[l]>a[i])
	largest=l;
	else
	largest=i;
	if(r<=h&&a[r]>a[largest])
	largest=r;
	if(largest!=i){
	ke=a[i];
		a[i]=a[largest];
		a[largest]=ke;
		maxheap(a,largest);
	}
}

void aaa(int a[],int i,int k){
		
	int s;
	a[i]=k;
	while(i>1 && a[i/2]<a[i]){
	s=a[i/2];
		a[i/2]=a[i];
		a[i]=s;
		i/=2;
	}
}
void insert(int a[],int k){
	h++;
	a[h]=-INF;
	aaa(a,h,k);
}
int extractmax(int a[]){
int ke=a[1];
	a[1]=a[h];
	h--;
	maxheap(a,1);
	
	return ke;
}
main(){
	int key,a[INF];
	string s;
	while(1){
	cin>>s;
		if(s=="end")
		break;
		else if(s=="insert"){
			scanf("%d",&key);
			insert(a,key);
		}
		else 
			printf("%d\n",extractmax(a));
		
	}
	return 0;
}

