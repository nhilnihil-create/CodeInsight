#include <iostream>

using namespace std;

int main(){
	int row[]= {1, 1, 1, 2, 1, 2, 1, 5, 2, 2, 1, 5, 1, 2, 1, 14, 1, 5, 1, 5, 2, 2, 1, 15, 2, 2, 5, 4, 1, 4, 1, 51};
	int k;
	cin>>k;
	if(k>=1 && k<=32){
	cout<<row[k-1]<<"\n";
}

	return 0;
	}
