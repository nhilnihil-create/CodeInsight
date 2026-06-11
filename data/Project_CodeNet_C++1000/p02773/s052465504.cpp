#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 1e9;
const ll LINF = 1e18;
const int mod = 1e9+7;

#define pi pair<int,int>
#define pl pair<lld,lld>

#define dump(x) cout << #x << " = " << (x) << endl
#define YES(n) cout << ((n) ? "YES" : "NO"  ) << endl
#define Yes(n) cout << ((n) ? "Yes" : "No"  ) << endl
#define SANKOU(n,a,b) cout << ((n) ? (#a) : (#b) ) << endl

#define mem0(x) memset(x,0,sizeof(x))
#define fillnum(x,n) fill(begin(x),end(x),n)
#define asort(x) sort(x.begin(),x.end())
#define dsort(x,t) sort(x.begin(),x.end(),greater<t>())
#define vuniq(x) x.erase(unique(x.begin(), x.end()), x.end())

#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)

int main() {
    ll N;
    cin >> N;
    vector<string> S;
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        S.pb(s);
    }
    asort(S);
    queue<string> que;
    ll maxcnt = 0;
    ll cnt = 1;
    string now = S[0];
    for (int i = 1; i < N; i++) {
        if(now == S[i]){
            cnt++;
        } else {
            if(maxcnt < cnt){
                while(!que.empty()) que.pop();
                maxcnt = cnt;
                que.push(now);
            } else if(maxcnt == cnt){
                que.push(now);
            }
            cnt = 1;
            now = S[i];
        }
    }
    if(maxcnt < cnt){
        while(!que.empty()) que.pop();
        maxcnt = cnt;
        que.push(now);
    } else if(maxcnt == cnt){
        que.push(now);
    }
    int size = que.size();
    for (int i = 0; i < size; i++) {
        cout << que.front() << endl;
        que.pop();
    }
}