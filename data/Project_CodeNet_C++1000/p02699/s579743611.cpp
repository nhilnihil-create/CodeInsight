#include <bits/stdc++.h>
#define SIZE 10
#define PI 3.141592653589793

using namespace std;
typedef long long ll;

int main(void){
	cin.tie(0);
	ios::sync_with_stdio(false);

	int S,W;
	int i,j;
	int tmp;
	int answer=0;
	int counter=0;
	vector<int> given;

	cin >> S >> W;

	if(S>W)
		cout << "safe" << endl;
	else
		cout << "unsafe" << endl;

	return 0;
}

