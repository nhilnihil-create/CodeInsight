#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define forin(in, n) for(int i=0; i<n; i++) cin>>in[i]
#define forout(out) for(int i=0; i<(int)out.size(); i++) cout<<out[i]<<" "
#define rep(i, n) for(int i=0; i<(n); i++)

int main(){
    int n, m; cin>> n >> m;
    ll ac=0, wa=0;
    vector<ll> isac(n, 0), iswa(n, 0);
    rep(i, m){
        int p;
        string s;
        cin>> p >> s;
        p--;
        if(s=="AC"){
            if(isac[p] == 0){
                ac++;
                wa += iswa[p];
                isac[p] = true;
            }
        }
        else iswa[p]++;
    }
    cout<<ac<<" " << wa << endl;
}