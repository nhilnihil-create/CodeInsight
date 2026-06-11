#include<iostream>
#include<string>
using namespace std;
int main(){
	int N;
	string dum;
	cin >> N >> dum;
	if(N >=dum.length()){
		cout << dum ;
	}
	else{
		for(int i=0; i<N; i++){
			cout << dum[i];
		}
		cout << "...";
	}
	return 0;
}