#include <iostream>
#include <string>
#include <utility>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;
typedef long long Int;
#define REP(i , x) for(int i = 1 ; i < x ; ++i)


int main()
{
	REP(i, 10){
		REP(j, 10){
			cout << i << "x" << j << "=" << i*j << endl;
		}
	}

	return 0;
}