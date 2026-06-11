#include<bits/stdc++.h>
#define rep(i,N) for(int i=0;i<(N);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
using namespace std;
const long long MOD = 1e9 + 7;
const long long INF = 1e12;
const int inf = 1e9;
const int mod = 1e9+7;
typedef long long ll;
typedef pair<ll,int> P;
typedef set<int> S;
int main(){
    cout << fixed << setprecision(10);
    deque<char> deq;
    string s;
    cin >> s;
    for(auto u : s){
        deq.push_back(u);
    }
    int q;
    cin >> q;
    int rev = 0;
    rep(i,q){
        int t;
        cin >> t;
        if(t == 1) rev ^= 1;
        else{
            int f;
            char ss;
            cin >> f >> ss;
            if(f == 1){
                if(rev == 1) deq.push_back(ss);
                else deq.push_front(ss);
            }else{
                if(rev == 1) deq.push_front(ss);
                else deq.push_back(ss);
            }
        } 
    }
    /*
    cout << "end" << endl;
    for(auto u : deq) cout << u << endl;
    cout << endl;*/
    if(rev == 1){
        reverse(deq.begin(),deq.end());
    }
    for(auto u : deq) cout << u;
    cout << endl;
    return 0;
}