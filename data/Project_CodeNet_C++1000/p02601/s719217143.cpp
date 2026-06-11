#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef tree<ii,null_type,less<ii>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	int a,b,c; cin>>a>>b>>c;
	int k; cin>>k;
	for (int i=0; i<k; i++) {
		if (a>=b) b*=2;	
		else {
		if (b>=c) c*=2;
		}
	}
	cout<<(a<b&&b<c?"Yes":"No")<<endl;
	return 0;
}
