/*input

*/
#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
#define MAX 100005
#define pb push_back
#define mp make_pair


using namespace std;
using namespace std::chrono;


signed main(){
	int x,y;
	cin >> x >> y;
	int price[]={0,300000,200000,100000,0};
	int tot = price[min(x,4LL)]+price[min(y,4LL)];
	if(tot == 600000)
		tot += 400000;
	cout << tot << '\n';
}
