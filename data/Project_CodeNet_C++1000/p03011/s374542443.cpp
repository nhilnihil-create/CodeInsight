#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<utility>
#include<cstdio>
#include<map>
#include<vector>
#include<set>
#define pb push_back
#define st first
#define nd second
#define all(v) (v).begin(),(v).end()
using namespace std;
typedef long long lo;
const int mod=1000000007,N=500005;
lo a,b,c,d,e,g=1,arr[N],h[N];

void solve(){
	cin >> a >> b >> c;
	cout << a+b+c-max(a,max(b,c)) << endl;
}

int main(){
	// freopen("in.txt","r",stdin);
	// freopen("out.txt","w",stdout);
	// cin >> g;
	while(g--) solve();
}