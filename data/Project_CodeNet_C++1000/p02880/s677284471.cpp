#include<iostream>
using namespace std;

int n;
bool ada=false;
int main(){
	cin>>n;
	for (int i=1; i<=9; i++){
		for (int j=1; j<=9; j++){
			if (n==i*j){
				ada=true;
			}
		}
	}
	if(ada){
		cout<<"Yes"<<endl;
	}else{
		cout<<"No"<<endl;
	}
}