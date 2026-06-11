#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<utility>
#include<cstdio>
#include<map>
#include<vector>
#include<set>
#include<cassert>
#define pb push_back
#define st first
#define nd second
#define all(v) (v).begin(),(v).end()
using namespace std;
typedef long long lo;
const int mod=1000000007,N=500005;
lo a,b,c,d,e,g=1,h[N];
pair<lo,lo>arr[N];
void solve(){
	cin >> a;
	for(lo i=1;i<=a;i++){
		cin >> arr[i].nd >> arr[i].st;
	}
	sort(arr+1,arr+a+1);
	lo x=0;
	for(lo i=1;i<=a;i++){
		x+=arr[i].nd;
		if(x>arr[i].st){
			cout << "No" << endl;
			return;
		}
	}
	cout << "Yes" << endl;
}

int main(){
	// freopen("in.txt","r",stdin);
	// freopen("out.txt","w",stdout);
	// cin >> g;
	while(g--)solve();
}