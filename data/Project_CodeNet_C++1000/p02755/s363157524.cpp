#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector <int> n;

int main(){
	int a,b,c,d,i;
	cin>>a>>b;
	for(int i=1;i<1100;i++){
		c=i*0.08;
		d=i*0.1;
		if(c==a&&d==b){
			cout<<i<<endl;
			return 0;
		}
	}
	cout<<-1<<endl;
	return 0;
}
