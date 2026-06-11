// DISCO-A.cpp
//#include "pch.h"
#include <iostream>
using namespace std;
int main()
{
	int X, Y;
	cin >> X >> Y;
	int prize = 0; // 獲得賞金
	if (X == 3)
	{
		prize += 100000; // prize=prize+100000と同じ意味
	}
	if (Y == 3)
	{
		prize += 100000;
	}
	if (X == 2)
	{
		prize += 200000;
	}
	if (Y == 2)
	{
		prize += 200000;
	}
	if (X == 1)
	{
		prize += 300000;
	}
	if (Y == 1)
	{
		prize += 300000;
	}
	if (X==1&&Y==1) // 両方で１位の時はボーナスありで１００万円になる
	{
		prize = 1000000;
	}
	cout << prize << endl;
}
