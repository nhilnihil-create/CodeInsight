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
const int MOD=1e9 + 7;
const int N=1000100;
template<typename T> istream &operator>>(istream &is, vector<T> &vec){  
                                                        for (auto &v : vec) is >> v; return is; }
#define dbg(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ") " << __FILE__ << endl;

void solve(){
    long n;
    cin>>n;
    bool ff=true;
    for(int i=0;i<n;i++){
        long x;
        cin>>x;
        if(x%2) continue;
        if(!(x%3==0 || x%5==0)){
            ff=false;
        }
    }
    if(ff){
        cout<<"APPROVED";
    } else {
        cout<<"DENIED";
    }
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
