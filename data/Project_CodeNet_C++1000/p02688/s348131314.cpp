#include <bits/stdc++.h>
using namespace std;




int main() {
	int N, K,hav,tmp,count=0;
	cin >> N >> K;
	vector<bool> sNum(N,0);
	for (int i = 0; i < K ; i++)
	{
		cin >> hav;
		for (int j =0; j < hav; j++)
		{
			cin >> tmp;
			sNum.at(tmp-1) = 1;
		}
	}
	
	for (int i = 0; i < N; i++)
	{
		if (sNum.at(i) == 0)count++;
	}
	cout << count << endl;
}