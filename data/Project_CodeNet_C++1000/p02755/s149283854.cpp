#include <bits/stdc++.h>
#define SIZE 10
#define PI 3.141592653589793

using namespace std;
typedef long long ll;

int main(void){
	cin.tie(0);
	ios::sync_with_stdio(false);

	int i,j;
	int tmp;
	int answer=0;
	int counter=0;
	ll A,B;
	ll price;
	vector<int> given;

	cin >> A >> B;

	for(price=1;price<=5000000;price++){
		//cout << price*80/100 << " " << price*100/100 << endl;
		if(price*80/1000==A && price*100/1000==B){
			cout << price << endl;
			return 0;
		}
	}
	
	cout << -1 << endl;

	return 0;
}

