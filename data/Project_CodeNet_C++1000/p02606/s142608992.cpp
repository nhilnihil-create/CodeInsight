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

	int ans=0,L,R,d,cnt=0;
	cin>>L>>R>>d;
	for (int i = L; i <=R; ++i)
	{
		cnt=0;
		if(i%d==0){
			cnt++;

		}
		ans+=cnt;
	}

cout<<ans<<endl;
return 0;
}
