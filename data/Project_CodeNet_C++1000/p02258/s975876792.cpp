#include <iostream>
using namespace std;
static const int MAX = 200000;
static const int MIN = -1000000000;

int main()
{
	int a,n,temp;
	int count=0;
	long m = MIN;
	int index = 0;
	int buf[MAX];

	cin >> n;
	for(int i=0; i<n; i++){
		cin >> buf[i];
	}

	temp = buf[0];
	for(int j=1; j<n; j++){
		// cout << buf[j];
		if(m < buf[j]-temp){
			m = buf[j] - temp;
		}
		if(temp > buf[j]){
			temp = buf[j];
		}
	}

	cout << m << endl;

	return 0;
}