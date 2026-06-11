#include "bits/stdc++.h"
using namespace std;
#define rep(i,n)for(int i=0;i<(int)(n);i++)
#define PI 3.141592653589793
//vector < vector<int>>a(0, vector<int>(0));二次元配列宣言


int main()
{
	int n, d;
	cin >> n >> d;
	vector < vector<int>>x(n, vector<int>(d));
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < d; j++)
		{
			cin >> x.at(i).at(j);
		}
	}
	int cnt=0;
	int k,l;
	int sum;
	for (i = 0; i < n - 1; i++)
	{
		for (l = i + 1; l < n; l++)
		{
			sum = 0;
			for (j = 0; j < d; j++)
			{
				sum += (abs(x.at(i).at(j) - x.at(l).at(j))) * (abs(x.at(i).at(j) - x.at(l).at(j)));
				//cout <<i<<" "<<l<<" "<<j<<" "<< x.at(i).at(j) <<" "<< x.at(l).at(j)<< " "<<sum << endl;
			}
			//cout << sum << endl;
			
			for (k = 1; k <= 1000; k++)
			{
				if (sum == k * k)
					cnt++;
			}
		}
	}
	cout << cnt << endl;
}