#include<bits/stdc++.h>
#define rep(i,a) for(int (i)=0; (i)<(a); (i)++)
#define rep2(i,a,b) for(int (i)=(a); (i)<(b); (i)++)
#define MOD 1000000007
#define all(v) v.begin(), v.end()
#define m0(x) memset(x,0,sizeof(x))
#define chmax(a,b) if(b>a) a = b
#define chmin(a,b) if(b<a) a = b
typedef long long ll;
using namespace std;



int dp[20050];
int main(){
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int a,b,c; cin >> a >> b >> c;
        if(a == b && b != c) cout << "Yes" << endl;
        else if(a == c && b != c) cout << "Yes" << endl;
        else if(b == c && a != b) cout << "Yes" << endl;
  		else cout << "No" << endl;
        return 0;
}