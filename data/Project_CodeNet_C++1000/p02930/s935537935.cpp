#include<iostream>
#define ll long long
#define mp make_pair
using namespace std;
int main(){
	int n;cin>>n;
	for(int i=0;i<n;++i){
		for(int j=i+1;j<n;++j){
			int k=i^j,c=0;
			for(;!(k>>c&1);++c);
			cout<<c+1<<' ';
		}
		cout<<endl;
	}
}