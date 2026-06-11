#include<iostream>
#define loop(i,a,b) for(int i=a;i<b;i++)
using namespace std;
int main(){
	loop(i,1,10)
		loop(j,1,10)
			cout<<i<<"x"<<j<<"="<<i*j<<endl;
}