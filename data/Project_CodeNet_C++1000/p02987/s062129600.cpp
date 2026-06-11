#include <iostream>
using namespace std;

char arr[4];
int freq[30]={};

int main() {
	
	for (int i=0;i<4;i++){cin>>arr[i];}
	for(int i = 0 ; i < 4 ; ++i)    freq[arr[i] - 'A']++;
	for (int i=0;i<30;i++){
		
	 if (freq[i]==1||freq[i]>2){
	 	cout << "No" <<endl;
	 	return 0;
	}
	
	}
	cout<<"Yes"<<endl;
	return 0;
}
