#include <iostream>
#include <cstdio>
#include <cstring>
#include <sstream>
#include <algorithm>
#include <math.h>
#include <map>
#include <functional>
#include <iomanip>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <typeinfo>
#define PI 3.14159265359
#define INF 99999999
#define rep(i, n) for(int i=0; i<n; i++)
#define REP(n) rep(i, n)
#define EPS 1e-10
#define pb push_back
#define mp make_pair
typedef long long ll;
using namespace std;
typedef pair<int, int> P;

string getReverse(string str);
bool isLeap(int y);
ll gcd(ll a, ll b);
ll lcm(ll a, ll b);
double distanceAB(double xa, double ya, double xb, double yb);
void trace(int A[], int N);

/*
class Target
{
public:
	vector <string> draw(int n)
	{

	}
};
*/


int mcxiToInt(string str)
{
	map<char, int> tbl;
	int ret = 0;
	
	tbl['m'] = 1000;
	tbl['c'] = 100;
	tbl['x'] = 10;
	tbl['i'] = 1;
	
	rep(i, str.length())
	{
		if (isdigit(str[i]))
		{
			ret += (str[i] - '0') * tbl[str[i + 1]];
			i++;
		} else {
			ret += tbl[str[i]];
		}
	}
	
	return ret;
}

string getMcxi(int num)
{
	string ret = "";
	char temp[1000];
	
	if (num / 1000 >= 2)
	{
		sprintf(temp, "%dm", num / 1000);
		ret = temp;
	} else if (num / 1000 == 1) {
		ret += "m";
	}
	
	num %= 1000;
	
	if (num / 100 >= 2)
	{
		sprintf(temp, "%dc", num / 100);
		ret += temp;
	} else if (num / 100 == 1) {
		ret += "c";
	}
	
	num %= 100;
	
	if (num / 10 >= 2)
	{
		sprintf(temp, "%dx", num / 10);
		ret += temp;
	} else if (num / 10 == 1) {
		ret += "x";
	}
	
	num %= 10;
	
	if (num / 1 >= 2)
	{
		sprintf(temp, "%di", num / 1);
		ret += temp;
	} else if (num / 1 == 1) {
		ret += "i";
	}
	
	return ret;
}


int main()
{
	int n;
	string inp1, inp2;
	
	cin >> n;
	rep(i, n)
	{
		cin >> inp1 >> inp2;
		cout << getMcxi(mcxiToInt(inp1) + mcxiToInt(inp2)) << endl;
	}
	
	return 0;
}


string getReverse(string str)
{
	string ret = "";
	for (int i=str.length()-1; i>=0; i--)
	{
		ret += str.substr(i, 1);
	}
	return ret;
}

bool isLeap(int y)
{
	return y % 400 == 0
						? true : y % 100 == 0
						? false : y % 4 == 0
						? true : false;
}

ll gcd(ll a, ll b)
{
	return (b > 0) ? gcd(b, a % b) : a;
}

ll lcm(ll a, ll b)
{
	return a / gcd(a, b) * b;
}

void trace(int A[], int N)
{
	REP(N)
	{
		if (i > 0) cout << " ";
		cout << A[i];
	}
	cout << endl;
}

double distanceAB(double xa, double ya, double xb, double yb)
{
	return sqrt((xb-xa)*(xb-xa) + (yb-ya)*(yb-ya));
}