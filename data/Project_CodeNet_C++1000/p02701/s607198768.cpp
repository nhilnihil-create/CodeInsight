
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
const ll INF = 1LL << 60;



int main(){
    int n;
    cin >> n;
    map<string, int> smap;
    int ans=0;
    for(int i=0; i<n; i++){
        string s;
        cin >> s;
        smap[s] ++;
        if(smap[s] == 1) ans++;
    }
    cout << ans << endl;

   

}