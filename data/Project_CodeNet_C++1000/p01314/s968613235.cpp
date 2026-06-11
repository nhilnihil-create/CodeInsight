#include<iostream>
#include<iomanip>
#include<algorithm>
#include<string>
#include<map>
#include<cmath>
#include<queue>	

using namespace std;

namespace MyLib {
#define ALL(a) a.begin(),a.end()
#define REP(i,n) for(int i=0;i<n;i++)
#define RREP(i,n) for(int i=n-1;i>=0;i--)
#define debug(x) if(1)cout<<#x<<":"<<x<<endl;
#define DEBUG(x) if(1)cout<<#x<<":"<<x<<endl;
#define ll long long
}

using namespace MyLib;


int main() {
	int n;
	while (cin >> n, n) {
		int count = 0;
		for (int i = 1; i < n; i++)
			for (int j = i + 1; j < n; j++)
				if (j*(j + 1) / 2 - i*(i - 1) / 2 == n)
					count++;
		cout << count << endl;



	}
	return 0;

}