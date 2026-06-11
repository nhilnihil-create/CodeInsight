#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define rep2(i,x,n) for(int i=x; i<(n); i++)
#define ALL(n) begin(n),end(n)
struct cww{cww(){ios::sync_with_stdio(false);cin.tie(0);}}star;
const long long INF = numeric_limits<long long>::max();
typedef long long ll;
int main(){
    int n,k,q,a;
    cin >> n >> k >> q;
    vector<int>score(n,k-q);
    rep(i,q){
        cin >> a;
        score[a-1]++;
    }
    
    rep(i,n)cout << (score[i]>0?"Yes":"No") << endl;

    return 0;
}