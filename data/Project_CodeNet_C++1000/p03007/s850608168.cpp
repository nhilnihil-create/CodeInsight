#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

typedef pair<int,int> P;

int main(){
	int n;
	int a[100010];
	scanf("%d",&n);
	for(int i = 0 ; i < n ; i ++){
		scanf("%d",&a[i]);
	}
	
	int p=-10000,m=10000;
	int ret = 0;
	vector<int> vec;
	for(int i = 0 ; i < n ; i ++){
		p = max( p , a[i] );
		m = min( m , a[i] );
		ret += max( a[i] , -a[i] );
	}
	if(m > 0)cout << ret-2*m << endl;
	else if(p < 0)cout << ret+2*p << endl;
	else cout << ret << endl;
	
	int x = p,y = m;
	int pi = -1, mi = -1;
	for(int i = 0 ; i < n ; i ++){
		if(a[i] == p && pi == -1){
			pi = i;
			continue;
		}
		if(a[i] == m && mi == -1){
			mi = i;
			continue;
		}
		if(a[i] >= 0){
			printf("%d %d\n",y,a[i]);
			y -= a[i];
		}
		else {
			printf("%d %d\n",x,a[i]);
			x -= a[i];
		}
	}
	printf("%d %d\n",x,y);
}