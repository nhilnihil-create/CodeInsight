#include <iostream>
#include <string>
#include <math.h>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
#include <set>
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;


int main() {

int N,cnt=0,ans=0;
cin>>N;
int a[N+5];
for (int i = 1; i <= N; ++i)
{
	cin>>a[i];
}

for (int i = 1; i <= N; ++ ++ i)
{
	cnt=0;
	if (a[i]%2==1)
	{
		cnt++;
	}
	ans+=cnt;
}

cout<<ans<<endl;
return 0;
}
