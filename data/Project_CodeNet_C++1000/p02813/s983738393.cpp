/*
 _ _ _   _    _   _    _   _ _ _   _    _   _ __ _   __       __
|  _ _| | |  | | | |  | | |  _  | | |  | | |  __  | |   \   /   |
| |_ _  | |__| | | |  | | | |_| | | |__| | | |__| | | |\ \_/ /| |
|_ _  | |  __  | | |  | | |  _ <  |  __  | |  __  | | | \   / | |
 _ _| | | |  | | | |__| | | |_| | | |  | | | |  | | | |  \_/  | |  _   _   _
|_ _ _| |_|  |_| |_ __ _| |_ _ _| |_|  |_| |_|  |_| |_|       |_| |_| |_| |_|

*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define fi first
#define se second
#define pb push_back
#define all(a) (a).begin(), (a).end()
#define debug(a) cout << #a << " = " << a << " ";
#define endl "\n"
const int  MOD=1000000007;
const int N=1000100;
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }
#define dbg(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ") " << __FILE__ << endl;

void solve(){
    int N; cin >> N;
    vector<int> P(N),Q(N);
    for(int i=0; i<N; i++){
        cin >> P.at(i);
    }
    for(int i=0; i<N; i++){
        cin >> Q.at(i);
    }
    vector<int> order(N);
    for(int i=0; i<N; i++){
        order.at(i)=i+1;
    }
    int a,b;
    int now=1;
    do{
        int cntp=1; int cntq=1;
        for(int i=0; i<N; i++){
            if(order.at(i)!=P.at(i)) cntp=0;
            if(order.at(i)!=Q.at(i)) cntq=0;
        }
        if(cntp==1) a=now;
        if(cntq==1) b=now;
        now++;
    }while(next_permutation(order.begin(),order.end()));
    cout << abs(a-b) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long int t = 1;
    // cin>>t;
    for (long int tt = 1; tt <= t; tt++) {
        solve();
    }
    return 0;
}
