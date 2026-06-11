#include<iostream>
using namespace std;

int main(){
	int n;
  	cin>>n;
  	int i;
	int d[100][2];
  	for(i=0;i<n;i++){
    	cin>>d[i][0]>>d[i][1];
    }
  	for(i=0;i<n-2;i++){
    	if(d[i][0]==d[i][1]&&d[i+1][0]==d[i+1][1]&&d[i+2][0]==d[i+2][1]){
        	cout<<"Yes";
          	return 0;
        }
    }
  	cout<<"No";
}
