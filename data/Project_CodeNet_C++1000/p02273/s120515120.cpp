#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <functional>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <bitset>
#include <climits>
#include <iterator>
 
#define all(c) (c).begin(), (c).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define pb(e) push_back(e)
#define mp(a, b) make_pair(a, b)
#define fr first
#define sc second
 
const int INF=100000000;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
using namespace std;
typedef pair<int ,int > P;
typedef long long ll;

typedef pair<float, float> point;
typedef vector<point> segments;


void print_array(segments list)
{
	for (int i = 0; i < list.size(); i++)
	{
		cout << list[i].fr << " " << list[i].sc << endl;
	}
}

void print_point(point pt)
{
	cout << pt.fr << " " << pt.sc << endl;
}



void koch(int n, point p1,point p2)
{
	if (n == 0)
	{
		return;
	}
	point s=std::make_pair((2*p1.first+p2.first)/3,(2*p1.second+p2.second)/3);
    point t=std::make_pair((p1.first+2*p2.first)/3,(p1.second+2*p2.second)/3);
    float ux=(s.first+std::cos(M_PI*60/180)*(t.first-s.first)-std::sin(M_PI*60/180)*(t.second-s.second));
    float uy=(s.second+std::sin(M_PI*60/180)*(t.first-s.first)+std::cos(M_PI*60/180)*(t.second-s.second));
    point u=std::make_pair(ux,uy);
    koch(n-1, p1, s);
    print_point(s);
    koch(n-1, s, u);
    print_point(u);
    koch(n-1, u, t);
    print_point(t);
    koch(n-1, t, p2);

}

int main()
{
	int n; cin >> n;
	segments segment;
	point p1 = mp(0, 0);
	point p2 = mp(100, 0);
	print_point(p1);
	koch(n, p1, p2);
	print_point(p2);
	return 0;
}