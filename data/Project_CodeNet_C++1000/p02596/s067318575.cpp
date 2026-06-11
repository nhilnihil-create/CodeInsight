#include<bits/stdc++.h>
using namespace std;
int main(){
	long long int N;
  	cin >> N;
	int value=7;
	int count =1;
	for(long long int i=0;i<N;i++){
		if(value % N==0){
			cout << count << endl;
			return 0;
		}
		else{
			value=((value*10)+7)%N;
		}
		count +=1;
	}
	cout << "-1" << endl;
  return 0;
}