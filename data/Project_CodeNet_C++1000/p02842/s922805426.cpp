#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	//int lo= 1, hi=50000, mid;
	//double x=-1;
	int i;
	bool flag = false;
	for(i=1; i<=(n+1); i++){
		if(int(i*1.08)==n){
			//x = n;
			flag = true;
			break;
		}
	}
	if(flag){
		cout << i << endl;
	}
	else{
		cout << ":(" << endl;
	}
	return 0;
}
