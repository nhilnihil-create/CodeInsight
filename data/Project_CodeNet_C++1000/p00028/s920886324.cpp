#include <iostream>
using namespace std;

int main()
{
	int val[100] = {0};
	int i;
	while(cin >> i){
		val[i]++;
	}
	int rec=0;
	for(int i=0;i<100;i++)
		rec = max(rec,val[i]);
	for(int i=0;i<100;i++)
		if(val[i]==rec)
			cout << i << endl;
	return 0;
}