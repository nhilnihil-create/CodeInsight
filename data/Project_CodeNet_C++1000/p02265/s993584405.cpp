#include<iostream>
#include<string>
using namespace std;

int a[5000000];
int first=0,last=0;
int n,m,q;
string w;

void insert(){
	a[last]=n;
	last++;
}

void deleteFirst(){
	last--;
}

void deleteLast(){
	first++;
}

void _delete(){
	for(int k=last-1;k>=first;k--){
		if(a[k]==n){
			m=k;
			for(int k=m;k<last-1;k++){
				a[k]=a[k+1];
			}
			last--;
			break;
		}
	}
}

void owata(){
	for(int k=last-1;k>=first;k--){
		cout<<a[k];
		if(k==first){
			cout<<endl;
		}
		else{
			cout<<' ';
		}
	}
}

void hantei(){
	if(w=="insert"){
		cin>>n;
		insert();
	}
	if(w=="delete"){
		cin>>n;
		_delete();
	}
	if(w=="deleteFirst"){
		deleteFirst();
	}
	if(w=="deleteLast"){
		deleteLast();
	}
}

int main(){
	cin>>q;
	for(int i=0;i<q;i++){
		cin>>w;
		hantei();
	}
	owata();
	return 0;
}