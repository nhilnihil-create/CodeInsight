#include <iostream>
#include <cstdio>
#include <string>
#include <sstream>
#include <algorithm>
#include <math.h>
#include <map>
#include <iomanip>
#include <vector>
#include <queue>

#define PI 3.14159265359

#define INF 1000000;

#define rep(i,n) for(int i=0;i<n;i++)
#define REP(n) rep(i,n)

using namespace std;


/*
class ElectronicPetEasy
{
public:
	string isDifficult(int st1, int p1, int t1, int st2, int p2, int t2)
	{
		
	}
};
*/


int main()
{
	int N, M;
	string U, T;
	vector<string> ids;
	bool key = false;
	
	cin >> N;
	REP(N)
	{
		cin >> U;
		ids.push_back(U);
	}
	cin >> M;
	REP(M)
	{
		cin >> T;
		if (find(ids.begin(), ids.end(), T) != ids.end())
		{
			//見つかった場合
			if (key)
			{
				cout << "Closed by " << T << endl;
				key = !key;
			} else {
				cout << "Opened by " << T << endl;
				key = !key;
			}
		} else {
			cout << "Unknown " << T << endl;
		}
	}
	
	return 0;
}