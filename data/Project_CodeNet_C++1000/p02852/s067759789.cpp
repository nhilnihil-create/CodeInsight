#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<n; i++)
#define PI 3.14159265359
#define INF 1000100100
#define all(x) (x).begin(),(x).end()
typedef long long ll;
#define P pair<ll, ll>
#define PP pair<P,P>
using namespace std;

int main(){
  	int n,m; cin >> n >> m;
    string s; cin >> s;
    int sl=s.length();
    //int times=0;
    int now=0;
    /*
    while(now<sl-1){
        bool can=false;
        for(int i=m; i>0; i--){
            if(now+i>=sl) continue;
            if(s[now+i]=='0'){
                now+=i;
                times++;
                can=true;
                break;
            }
        }
        if(!can){
            cout << -1 << endl;
            return 0;
        }
    }
*/
    vector<int> ans;
    now=sl-1;

    while(now>0){
        bool can=false;
        for(int i=m; i>0; i--){
            if(now-i<0) continue;
            if(s[now-i]=='0'){
                now-=i;
                ans.push_back(i);
                can=true;
                break;
            }
        }
        if(!can){
            cout << -1 << endl;
            return 0;
        }
    }
    reverse(all(ans));
    rep(i,ans.size()) printf("%d ",ans[i]);
    return 0;
}
