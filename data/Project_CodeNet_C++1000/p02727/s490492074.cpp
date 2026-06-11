#include <bits/stdc++.h>
using namespace std;

#define rep(i, a) for (int i = 0; i < (a); i++ )

 
typedef pair<int,int> P;
typedef long long ll;
 
const int INF = 1001001001;
const int MOD = 1000000007;
const double PI=acos(-1);

int main(){
    int X,Y,A,B,C;
    cin >> X >> Y >> A >> B >> C;

    vector<int> R,G,W;

    rep(i,A) {
        int a;
        cin >> a;
        R.push_back(a);
    }

    rep(i,B) {
        int b;
        cin >> b;
        G.push_back(b);
    }

    rep(i,C) {
        int w;
        cin >> w;
        W.push_back(w);
    }

    sort(R.begin(),R.end());
    reverse(R.begin(),R.end());
    sort(G.begin(),G.end());
    reverse(G.begin(),G.end());
    sort(W.begin(),W.end());
    reverse(W.begin(),W.end());

    vector<int> sa,sb;
    rep(x,X) {
        sa.push_back(R[x]);
    }
    rep(y,Y) {
        sb.push_back(G[y]);
    }

    reverse(sa.begin(),sa.end());
    reverse(sb.begin(),sb.end());

    int idxa,idxb;
    idxa = idxb = 0;

    rep(i,C) {
        int a = sa[idxa];
        int b = sb[idxb];
        int c = W[i];
        
        if (a<c && a<b) {
            sa[idxa] = c;
            idxa++;
            idxa = min(idxa, X-1);
        }
        else if (b<c) {
            sb[idxb] = c;
            idxb++;
            idxb = min(idxb, Y-1);
        }
        else {
            break;
        }
    }

    ll ans = 0;
    rep(i,sa.size()) {
        ll tmp = sa[i];
        ans += tmp;
    }
    rep(i,sb.size()) {
        ll tmp = sb[i];
        ans += tmp;
    }
    cout << ans << endl;
}
