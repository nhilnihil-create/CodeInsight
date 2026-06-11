#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
#define mp make_pair
#define pb push_back
#define f first
#define s second


//var 
int n, a[101];

int main(){
	ios_base::sync_with_stdio(0); 
	cin.tie(0);

	cin >> n;
	int ans = 0;
	for(int i = 1; i<=n; i++){
		cin >> a[i];
		if(i%2 && a[i]%2) ans++;
	}

	cout << ans << endl;

	cout.flush();
	return 0;
}