#include <iostream>
 
using namespace std;

int main()
{
	int x,y,z;
	int i,l;

	l=0;

	cin >> x;
	cin >> y;
	cin >> z;

		for(i=x;i<=y;i++){
			if((z%i)==0){
				l++;
			}
		}
	

	cout<<l<<endl;

	return 0;
}