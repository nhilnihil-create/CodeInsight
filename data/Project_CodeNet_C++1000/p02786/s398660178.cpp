#include <bits/stdc++.h>
using namespace std;

typedef vector< vector<int> > vvi;
typedef vector< vector<bool> > vvb;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef long long ll;

int main(){
    ll h;
    cin >> h;
    ll ans=0,cnt=1;
    while(h>0){
        h/=2;
        ans+=cnt;
        cnt*=2;
    }
    cout << ans << endl;
    return 0;
}