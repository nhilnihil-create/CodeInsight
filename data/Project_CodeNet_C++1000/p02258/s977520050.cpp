#include <iostream>

using namespace std;

static const int MAX =200000;
int main()
{

	int n, buff[MAX];
	cin >> n;

	for(int i=0;i<n;i++) cin >> buff[i];
	
	int minv=buff[0],maxv=-2000000000;

	for(int j=1;j<n;j++){
		if(maxv<buff[j]-minv) maxv=buff[j]-minv;
		if(buff[j]<minv) minv=buff[j];
	}

	cout <<maxv <<endl;
}

