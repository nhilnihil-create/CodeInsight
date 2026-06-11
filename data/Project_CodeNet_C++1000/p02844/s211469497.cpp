#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1000000007;
#define INF 1LL<<30
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()

int main(){
    int n;
    string s;
    cin>>n>>s;

    int ans=0;
    rep(i,1000){
        string t=to_string(i);
        if(t.size()==1) t="00"+t;
        else if(t.size()==2) t="0"+t;

        //cout<<t<<endl;
        int id=0;
        rep(j,n){
            if(s[j]==t[id]) id++;
            if(id==3){
                ans++;
                break;
            }
        }
    }

    cout<<ans<<endl;
}
