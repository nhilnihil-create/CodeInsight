#include <iostream>
#include <vector>
#include<list>
#include <algorithm>
#include <string>
#include <math.h>
#include<map>
#include <utility>
#include <iomanip>
#include<queue>
#include<set>
using namespace std;
#define REP(i,k,n) for(int i=k;i<n;i++)
 
#define INF 1844674407370955161
typedef long long int ll;
#define SIZE_OF_ARRAY(array) (sizeof(array)/sizeof(array[0]))
#define MOD 1000000007

template<typename T>
std::vector<T> enum_div(T n)//nの約数を列挙
{
	std::vector<T> ret;
	for(T i=1 ; i*i<=n ; ++i)
	{
		if(n%i == 0)
		{
			ret.push_back(i);
			if(i!=1 && i*i!=n)
			{
				ret.push_back(n/i);
			}
		}
	}
	return ret;
}


int N;
string S;
vector<vector<int>> li;
vector<int> siz;
bool judge(int len){
	map<string,int> s;
	string now=S.substr(0,len);
	REP(i,0,N-len+1){
		if(s.find(now)!=s.end()){
			int t=s.find(now)->second;
			if(t+len<=i){
				return true;
			}
		}else{
			s[now]=i;
		}
		now=S.substr(i+1,len);
	}
	return false;
}


int main()
{
	int M;
	cin>>M;
	ll d[M],c[M];
	ll ans=0;
	ll pot=0;
	REP(i,0,M){
		cin>>d[i]>>c[i];
		ans+=c[i];
		pot+=c[i]*d[i];
	}

	ans=ans+(pot-1)/9-1;
	
	cout<<ans<<endl;

	return 0;
}