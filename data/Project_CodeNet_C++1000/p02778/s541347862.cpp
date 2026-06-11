#include<iostream>
#include<string>
#include<array>
#include<vector>
using namespace std;

int main(){
	string s;
	cin>>s;

	int size = s.size();

	for(int i=0;i<size;i++){
		cout<<'x';
	}
	cout<<endl;

	return 0;
}