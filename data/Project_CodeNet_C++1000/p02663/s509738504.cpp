#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <fstream>
#include <string>
#include <math.h>
#include <cstdlib>
#include <istream>
#include <sstream>
#include <cctype>
#include <iomanip>
//cout << fixed << setprecision(20) << *** << endl;
#define rep(i,N) for(int i=0;i<(int)N;++i)
typedef long long ll;
using namespace std;
int main()
{
	ll H1,M1,H2,M2,K,ST,DEAD;
	cin>>H1>>M1>>H2>>M2>>K;
	ST=H1*60+M1;
	DEAD=H2*60+M2-K;
	cout<<DEAD-ST<<endl;
}