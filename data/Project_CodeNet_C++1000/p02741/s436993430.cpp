#include<iostream>
#include<string>
#include<algorithm>
#include<iomanip>
#include<cmath>
#include<cstdio>
#include<map>
#include<queue>
#include<assert.h>
#include<stdio.h>
#include<stack>
#include<cstring>
#include<fstream>
using namespace std;
#define goup(i,a,b) for(int i=a;i<b;i++)
#define Goup(i,a,b) for(int i=a;i<=b;i++)
#define godown(i,a,b) for(int i=a;i>b;i--)
#define Godown(i,a,b) for(int i=a;i>=b;i--)
#define Gohead(i,a,b) for(int i=a;i;i=b)
typedef long long ll;
const int MaxDegree = 0x3f3f3f;
const double Mod = 1e9 + 7;
const double PI = acos(-1);
int book[1005][1005];
int main()
{
	int T, element[45] = { 0,1, 1, 1, 2, 1, 2, 1, 5, 2, 2, 1, 5, 1, 2, 1, 14, 1, 5, 1, 5, 2, 2, 1, 15, 2, 2, 5, 4, 1, 4, 1, 51 };
	while (cin >> T)
	{
		cout << element[T] << endl;
	}
	return 0;
}