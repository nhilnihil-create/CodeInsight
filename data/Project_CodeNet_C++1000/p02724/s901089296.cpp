#include <iostream>
#include <vector>
using namespace std;
vector <int> n;

int main(){
	int x;
	cin>>x;
	cout<<x/500*1000+(x-x/500*500)/5*5<<endl;
	return 0;
}