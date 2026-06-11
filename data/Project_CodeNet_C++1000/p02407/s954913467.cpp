#include <iostream>
using namespace std;


 int main (){
	int n;
	int ary[100];
	cin >> n;
		for(int i=0;i<=n-1;++i){
		cin >> ary[i];
		}
		for(int k=n-1;k>=0;--k){
			if(k!=0){
				cout<<ary[k]<<" ";
			}
			else{
				cout << ary[k];
			}
		}
		cout <<endl;
	
	return 0;
}