#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, x ,n) for(int i = x; i < n; i++)
#define repr(i, n) for(int i = n; i >= 0; i--)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
int main(){
    int n;
    cin >> n;
    int a[n],b[n];
    rep(i,n){cin >> a[i];b[i]=a[i];}
    
    sort(b,b+n,greater<int>());
    rep(i,n){
        if(a[i]==b[0])cout << b[1] << endl;
        else cout << b[0] << endl;
    }
    
    
    
	return 0;
}