#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define rep2(i,x,n) for(int i=x; i<(n); i++)
#define ALL(n) begin(n),end(n)
struct cww{cww(){ios::sync_with_stdio(false);cin.tie(0);}}star;
const long long INF = numeric_limits<long long>::max();
typedef long long ll;
int main(){
    int n;
    cin >> n;
    ll a;
    map<int,int>count;
    rep(i,n){
        cin >> a;
        count[a]+=1;
        if(count[a]==2){
            cout << "NO";
            return 0;
        }
    }


    cout << "YES";
    return 0;
}