#include <bits/stdc++.h>
#define loop2(i, s, n, a) for (int i = int(s); i < int(n); i += a)
#define loop(i, s, n) loop2(i, s, n, 1)
#define rep(i, n) loop(i, 0, n)

#define pb push_back
#define all(in) in.begin(),in.end()

using ll = long long;
using ull = unsigned long long;
using namespace std;

const int mod = 2019;

int main(){
    int n, m; cin >> n >> m;
    string ans; if(n==1) ans = "0"; else if(n==2) ans = "10"; else ans = "100";

    int count1 = true;
    string count2 = "000";
    rep(i,m){
        int a; char b; cin >> a >> b; a--;
      	if(n>=2 && a==0 && b=='0'){
        	count1 = false; break;
      	}else if(count2[a] == '0'){
            ans[a] = b;
            count2[a] = '1';
        }else if(ans[a] != b){
            count1 = false;
            break;
        }
    }
    if(count1) cout << ans << endl;
    else cout << -1 << endl;
}

