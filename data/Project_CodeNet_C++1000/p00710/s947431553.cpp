#include<iostream>
#include<climits>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
#include<functional>
#include<stack>
#include<list>
#include<string>
using namespace std;
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,n) for(int i=0;i<(n);i++)
#define INF INT_MAX/3
#define ALL(a) (a).begin(),(a).end()
#define PII pair<int,int>
#define PCC pair<char,char>
#define PCI pair<char,int>
#define PIC pair<int,char>
#define MP make_pair
#define DEBUG(x) cout<<#x<<": "<<x<<endl

int main()
{
	while (1)
	{
		vector<int> N;
		int n, r;
		cin >> n >> r;
		for(int i=1;i<=n;i++)N.push_back(i);
		if (n == 0)break;
		REP(i, r)
		{
			int p, c;
			cin >> p >> c;
			for(int l=c;l>0;l--)
			{
				int k = n - p -c+1 ;
				int temp = *(N.begin() + k);
				N.push_back(temp);
				N.erase(N.begin() + k);
			}
		}
		cout << N[n-1] << endl;
	}
	return 0;
}