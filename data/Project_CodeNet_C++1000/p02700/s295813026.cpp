#include <bits/stdc++.h>
#define SIZE 10
#define PI 3.141592653589793

using namespace std;
typedef long long ll;

int main(void){
	cin.tie(0);
	ios::sync_with_stdio(false);

	int A,B,C,D;
	int i,j;
	int tmp;
	int answer=0;
	int counter=0;
	vector<int> given;

	cin >> A >> B >> C >> D;

	while(1){
		A-=D;
		C-=B;

		if(C<=0){
			cout << "Yes" << endl;
			return 0;
		}

		if(A<=0){
			cout << "No" << endl;
			return 0;
		}
	}
}

