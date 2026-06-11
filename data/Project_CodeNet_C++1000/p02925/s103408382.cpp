#include <string.h>
#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#include <istream>
#define INF 2147483647
#define LLINF 9223372036854775807
typedef long long ll;
using namespace std;
int a[1050][1050];
int lastday[1050];
int stake[1050];
int main(){
	memset(lastday,0,sizeof(lastday));
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		stake[i]=1;
		for(int j=1;j<n;j++){
			cin>>a[i][j];
		}
	}
	int days=0;
	int over=0;
	while(1){
		days++;
		bool flag=0;
		for(int i=1;i<=n;i++){
			if(lastday[i]==days)continue;
			int j=a[i][stake[i]];
			if(lastday[j]==days||!j)continue;
			int r=stake[i],l=stake[j];
			if(stake[i]<n&&stake[j]<n&&a[j][l]==i){
				stake[i]=r+1,stake[j]=l+1;
				lastday[i]=days,lastday[j]=days;
				flag=1;
				over++;
			}
		}
		if(!flag){
			days--;
			break;
		}
	}
	if(over!=n*(n-1)/2)cout<<-1<<endl;
	else cout<<days<<endl;
	return 0;
}