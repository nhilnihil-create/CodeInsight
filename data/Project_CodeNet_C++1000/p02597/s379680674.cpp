#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl

void solve(){
    int n;
    cin >> n;
    vector<int> prefix(n+1,0);
    string s;
    cin >> s;
    for(int i=0;i<n;i++){
        prefix[i+1]=prefix[i];
        if(s[i]=='R'){
            prefix[i+1]++;
        }
    }
    int cnt = 0;
    for(int i=0;i<prefix[n];i++){
        if(s[i]!='R'){
            cnt++;
        }
    }
    cout << cnt << endl;

}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    IOS;
    int T;
    T=1;
    //cin >> T;
    while(T--){
    solve();
    }

    

    return 0;
}
