#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, x ,n) for(int i = x; i < n; i++)
#define repr(i, n) for(int i = n; i >= 0; i--)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
int main(){
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    cout << (( ((c+(b-1))/b) <= ((a+(d-1))/d) ) ? "Yes":"No");
	return 0;
}