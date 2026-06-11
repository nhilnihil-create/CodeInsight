#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    ll n,k;
    cin >> n >> k;
    vector<ll> p(n);
    vector<ll> c(n);
    for(ll i=0; i<n; i++){
        ll _p;
        cin >> _p;
        p[i] = _p-1;
    }
    for(ll i=0; i<n; i++){
        cin >> c[i];
    }
    
    ll best = -INFINITY;
    for(ll start=0; start<n; start++){
        unordered_set<ll> steped;
        ll score = 0;
        ll mode = 0;
        ll turnparloop = INFINITY;
        ll scoreparloop = 0;
        ll loopstart = -1;
        ll _turnls = 0;
        ll _scorels = 0;
        ll now = start;
        ll turn = 0;
        for(; turn<k; turn++){
            if(mode==0 && steped.count(now)){
                mode = 1;
                _turnls = turn;
                _scorels= score;
                loopstart = now;
            }else if(mode==1 && loopstart==now){
                mode = 2;
                scoreparloop = score - _scorels;
                turnparloop  = turn - _turnls;
                break;
            }
            if(mode==0)steped.insert(now);
            now = p[now];
            score += c[now];
            best = max(best,score);
        }
        if(scoreparloop>0){
            ll loops = max(0ll,(k-turn -1)/turnparloop -1);
            score += scoreparloop*loops;
            turn  += turnparloop*loops;
            best = max(best,score);
            for(; turn<k; turn++){
                now = p[now];
                score += c[now];
                best = max(best,score);
            }
        }
    }
    cout << best;
    return 0;
}
