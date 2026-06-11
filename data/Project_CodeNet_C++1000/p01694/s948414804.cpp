#include <bits/stdc++.h>

using namespace std;

#define FOR(i,k,n) for(int i = (k); i < (n); i++)
#define REP(i,n) FOR(i,0,n)
#define INF 114514810
#define ll long long
#define ALL(a) (a).begin(),(a).end()
#define SORT(v) sort(ALL(v))
//#define scanf scanf_s
typedef pair<int, int> P;

int main()
{
	int n;
	while (cin >> n, n)
	{
		bool hidari = false; bool migi = false;
		string f[500];
		int cnt = 0;
		f[0] = "";
		FOR(i,1 ,n+1)
		{
			cin >> f[i];
			if (f[i] == "lu")
			{
				if (f[i - 1] == "ru") cnt++;
			}
			if (f[i] == "ru")
			{
				if (f[i - 1] == "lu") cnt++;
			}
			if (f[i] == "ld")
			{
				if (f[i - 1] == "rd") cnt++;
			}
			if (f[i] == "rd")
			{
				if (f[i - 1] == "ld") cnt++;
			}
		}
		cout << cnt << endl;

	}
	return 0;
}