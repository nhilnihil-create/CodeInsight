#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef tree<ii,null_type,less<ii>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	int h,w,n; cin>>h>>w>>n;
	int ret=INT_MAX;
	for (int x=0; x<=h; x++)
		for (int y=0; y<=w; y++)
			if (h*w-(h-x)*(w-y)>=n)
				ret=min(ret,x+y);
	cout<<ret<<endl;
	return 0;
}
