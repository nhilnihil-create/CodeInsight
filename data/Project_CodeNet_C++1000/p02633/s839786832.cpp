#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
#define mp make_pair
#define pb push_back
#define f first
#define s second


//var 
int x;

int main(){
	ios_base::sync_with_stdio(0); 
	cin.tie(0);

	cin >> x;
	cout << 360/__gcd(360, x) << endl;

	cout.flush();
	return 0;
}