#include <bits/stdc++.h>
using namespace std;

int main(){

	int bh, bm, ah;
	int am, total, si;

	cin >> bh >> bm >> ah >> am >> si;
	total = ((ah * 60) + am) - ((bh * 60) + bm);
	total = total - si;
	if(total > 0)
		cout << total << endl;
	else
		cout << "0" << endl;



	return 0;
}