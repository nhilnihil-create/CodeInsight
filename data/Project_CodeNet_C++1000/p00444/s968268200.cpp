#include<iostream>


using namespace std;
int main(void){
    while(1){
    int a;
	int n;
	int c=0;
	cin>>a;
    if(a==0)break;
	int count=0;
	for(n=1000-a;n!=0;c++){
        if(n>=500)n-=500;
        else if(n>=100)n-=100;
        else if(n>=50)n-=50;
        else if(n>=10)n-=10;
        else if(n>=5)n-=5;
        else if(n>=1)n-=1;
    }
    cout << c << endl;

    }
	return 0;
}