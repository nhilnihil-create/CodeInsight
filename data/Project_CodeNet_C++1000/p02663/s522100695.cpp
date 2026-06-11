#include <iostream>
#include <vector>
#include<list>
#include <algorithm>
#include <string>
#include <math.h>
#include<map>
#include <utility>
#include <cstring>
#include <iomanip>
#include<queue>
#include<set>
#include<stack>
#include<fstream>
using namespace std;
#define REP(i,k,n) for(int i=k;i<n;i++)
 
#define INF 1844674407370955161
typedef long long int ll;
#define SIZE_OF_ARRAY(array) (sizeof(array)/sizeof(array[0]))
#define MOD 1000000007


int main()
{
	int H1,H2,M1,M2,K;
	cin>>H1>>M1>>H2>>M2>>K;

	int up=60*H1+M1;
	int down=60*H2+M2;

	int ans=down-K-up;
	ans=max(0,ans);
	cout<<ans<<endl;
	
	return 0;
	
}