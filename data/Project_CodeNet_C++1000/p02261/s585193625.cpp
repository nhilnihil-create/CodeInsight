#include <iostream>
using namespace std;

struct data{
	char a;
	char b;
}; 

int BubbleSort(struct data *a,int n){
	int count=0;
	int flag=1;
	while(flag){
		flag=0;
		for(int i=n-1;i>0;i--){
			if(a[i].b<a[i-1].b){
				struct data temp=a[i];
				a[i]=a[i-1];
				a[i-1]=temp;
				flag=1;
				count++;
			}
		}
	}
}

int SelectionSort(struct data *a,int n){
	int count=0;
	for(int i=0;i<n-1;i++){
		int minj=i;
		for(int j=i+1;j<n;j++){
			if(a[minj].b>a[j].b){
				minj=j;
			}
		}
		if(minj!=i){
			struct data temp = a[minj];
			a[minj]=a[i];
			a[i]=temp;
			count++;
		}
	}
}


int main() {
	
	struct data d1[40];
	struct data d2[40];
	
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>d1[i].a>>d1[i].b;
		d2[i]=d1[i];
	}
	
	BubbleSort(d1,n);
	SelectionSort(d2,n);
	
	int flag=1;
	for(int i=0;i<n;i++){
		if(d1[i].a!=d2[i].a){
			flag=0;
			break;
		}
	}
	
	for(int i=0;i<n;i++){
		if(i>0) cout<<" ";
		cout<<d1[i].a<<d1[i].b;
	}
	cout<<endl;
	cout<<"Stable"<<endl;
	
	
	for(int i=0;i<n;i++){
		if(i>0) cout<<" ";
		cout<<d2[i].a<<d2[i].b;
	}
	cout<<endl;
	
	if(!flag){
		cout<<"Not stable"<<endl;
	}
	else{
		cout<<"Stable"<<endl;
	}
	
	return 0;
}