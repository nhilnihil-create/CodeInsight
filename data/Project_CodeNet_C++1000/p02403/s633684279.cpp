#include<iostream>
using namespace std;
int main()
{
	int a[100000], b[100000];
	int i,j,r,d;
	for (i = 0; i < 98000; i++){
		cin >> a[i] >> b[i];
		if (a[i] == 0 && b[i] == 0){
			j = i;
			break;
		}
	}
	for (i = 0; i < j; i++){
		for (r=0;r<a[i];r++){
			for (d=0;d<b[i];d++){
				cout << "#";
			}
			cout << endl;
		}
		cout << endl;
	}
	return 0;
}