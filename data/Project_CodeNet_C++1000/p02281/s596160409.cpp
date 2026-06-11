#include<iostream>
using namespace std;

int n;
int num[26][5];
int bl[26];
int fst;

int front(int a){
	if(a==-1) return 0;
	cout<<" "<<a;
	front(num[a][2]);
	front(num[a][3]);
}

int md(int a){
	if(num[a][2]!=-1) md(num[a][2]);
	cout<<" "<<a;
	if(num[a][3]!=-1) md(num[a][3]);
}

int la(int a){
	if(num[a][2]!=-1) la(num[a][2]);
	if(num[a][3]!=-1) la(num[a][3]);
	cout<<" "<<a;
}

int main(){
	cin>>n;
	int k;
	for(int i=0;i<=n-1;i++){
		cin>>k;
		cin>>num[k][2]>>num[k][3];
	}
	for(int i=0;i<=n-1;i++){
		if(num[i][2]!=-1) bl[num[i][2]]=1;
		if(num[i][3]!=-1) bl[num[i][3]]=1;
	}
	for(int i=0;i<=n-1;i++){
		if(bl[i]==0) {
			fst=i;
			break;
		}
	}
	cout<<"Preorder"<<endl;
	front(fst);
	cout<<endl;
	cout<<"Inorder"<<endl;
	md(fst);
	cout<<endl;
	cout<<"Postorder"<<endl;
	la(fst);
	cout<<endl;
	return 0;
}