#include <bits/stdc++.h>
using namespace std;
#define ref goto refrain

void bubble(int*a,char*c,int n);
void selection(int*a,char*c,int n);

int main(){
	int n;
	cin>>n;
	char suit[n],bs[n];
	int num[n],bn[n],j;
	char dou[9][4];//各数字のスーツの順番を記録
	memset(dou,'n',sizeof(dou));
	for(int i=0;i<n;i++){
		cin>>suit[i]>>num[i];
		for(j=0;dou[num[i]-1][j]!='n';j++);
		dou[num[i]-1][j]=suit[i];
		bs[i]=suit[i];
		bn[i]=num[i];
	}
	
	bubble(bn,bs,n);//バブルソート
	cout<<bs[0]<<bn[0];
	for(int i=1;i<n;i++){
		cout<<' '<<bs[i]<<bn[i];
	}
	cout<<endl;
	cout<<"Stable"<<endl;
	
	selection(num,suit,n);
	cout<<suit[0]<<num[0];
	for(int i=1;i<n;i++){
		cout<<' '<<suit[i]<<num[i];
	}
	cout<<endl;
	for(int i=1;i<n;i++){//安定か判別
		if(bs[i]!=suit[i]){
			cout<<"Not stable"<<endl;
			goto No;
		}
	}
	cout<<"Stable"<<endl;
	No:
	return 0;
}

void bubble(int*a,char*c,int n){
	for(int i=0;i<n;i++){
		for(int j=n-1;j>i;j--){
			if(a[j]<a[j-1]){
				int temp=a[j]; a[j]=a[j-1]; a[j-1]=temp;
				char cop=c[j]; c[j]=c[j-1]; c[j-1]=cop;
			}
		}
	}
}

void selection(int*a,char*c,int n){
	for(int i=0;i<n;i++){
		int min=i;
		for(int j=i;j<n;j++){
			if(a[min]>a[j]) min=j;
		}
		if(min!=i){
			int temp=a[i]; a[i]=a[min]; a[min]=temp;
			char cop=c[i]; c[i]=c[min]; c[min]=cop;
		}
	}
}