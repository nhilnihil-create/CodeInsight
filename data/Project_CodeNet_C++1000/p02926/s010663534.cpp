#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#pragma GCC target ("avx,avx2,tune=native")
#pragma GCC optimization ("unroll-loops")
#include "bits/stdc++.h"
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
typedef long long ll;
using namespace __gnu_pbds;
using namespace std;
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define len(v) ((int)v.size())
#define all(v) v.begin(), v.end()
#define oset tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define orz ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);    
#define inp freopen("input.txt","r",stdin);freopen("out.txt","w",stdout); 
ll mod=1e9+7;
void io(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);    
    
}
const int N=2e5+5;
int x[200],y[200];
bool cmp(const pair<int,int> &A,const pair<int,int> &B) {
	return atan2(A.second , A.first) < atan2(B.second , B.first);
}

int main() {
    io();
    int n;
    cin>>n;
    pair<int,int> a[200];
    for(int i=0;i<n;i++){
    	cin>>a[i].first>>a[i].second;

    }
    /*for(int i=0;i<n;i++){
		if(x[i]==0 && y[i]==0)
			continue;
		double tr=atan2(y[i],x[i]);
		th.push_back(tr);
		for(int j=0;j<n;j++){
			if(i == j)
				continue;
			if(x[j] == 0 && y[j] == 0)
				continue;
			double ts=atan2(y[j],x[j]);
			th.push_back((tr+ts)/2);
		}
	}*/
	sort(a,a + n,cmp);
	double ans = 0;
	for(int i = 0;i < n;++i) {
		double X = a[i].first,Y = a[i].second;
		ans = max(ans,X * X + Y * Y);
		for(int j = (i + 1) % n;j != i;j = (j + 1) % n) {
			X += a[j].first,Y += a[j].second;
			ans = max(ans,X * X + Y * Y);
		}
	}
	printf("%.10lf",sqrt(ans));
	return 0;

}
 


 