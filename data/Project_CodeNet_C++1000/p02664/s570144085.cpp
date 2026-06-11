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
	string T;
	cin>>T;
	int N;
	N=T.size();

	REP(i,0,N){
		if(T[i]!='P'&&T[i]!='D'){
			T[i]='D';
		}
	}
	cout<<T<<endl;

	
	return 0;
	
}