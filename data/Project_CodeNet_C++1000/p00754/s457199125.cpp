#include "bits/stdc++.h"

#define int long long
#define REP(i,a,n) for(int i=a;i<n;++i)
#define rep(i,n) REP(i,0,n)
#define REV(i,a,n) for(int i=n;i>=a;--i)
#define all(e) e.begin(),e.end()
#define rall(e) e.rbegin(),e.rend()
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define mod 1000000007
#define show(n) cerr<<#n<<" = "<<n<<endl
#define showp(n) cerr<<n.fs<<", "<<n.sc<<endl
#define shows(n) for(auto z:n){cerr<<z<<", ";}cerr<<endl
#define showsp(n) for(auto z:n){cerr<<z.fs<<" "<<z.sc<<", "}cerr<<endl

#define yes printf("yes\n")
#define no printf("no\n")
#define case(i) printf("Case #%lld: ",i)

using namespace std;

using vi=vector<int>;
using pint=pair<int,int>;

const int INF=1LL<<55;

string s;

void solve(){

    stack<int> st;
    rep(i, s.size()){
        if(s[i]=='('){
            st.push(0);
        }
        if(s[i]=='['){
            st.push(1);
        }
        if(s[i]==')'){
            if(st.empty() || st.top()!=0){
                no;
                return;
            }else{
                st.pop();
            }
        }
        if(s[i]==']'){
            if(st.empty() || st.top()!=1){
                no;
                return;
            }else{
                st.pop();
            }
        }
    }
    if(st.empty()) yes;
    else no;
}

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    while(getline(cin,s),s!="."){
        solve();
    }

    return 0;
}
