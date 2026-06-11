#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define ALL(a) a.begin(),a.end()

const double EPS = 1e-6;

int main(){
    string S, T; cin >> S >>T;
    ll nt = T.size();
    ll ns = S.size();
    unordered_map<char,int> mps, mpt;
    for(int i = 0; i < S.size(); i++) mps[S[i]]++;
    for(int i = 0; i < T.size(); i++) mpt[T[i]]++;
    double max = 0;
    //vector<char> ans;
    for(auto e: mpt){
        if(mps[e.first] == 0){
            cout << -1 << endl;
            return 0;
        }
        /* if(max + EPS < (double)e.second / (double)mps[e.first]){
            max = (double)e.second / (double)mps[e.first];
            ans.clear;
            ans.push_back(e.first);
        }else if(max + EPS > (double)e.second / (double)mps[e.first] && max - EPS < (double)e.second / (double)mps[e.first]){
            ans.push_back(e.first);
        } */
    }
    vector<int> tmp[26];
    for(int i = 0 ; i < S.size(); i++){
        int x = S[i] - 'a';
        tmp[x].push_back(i);
    }
    ll ans = 0;
    ll pre = 0;
    for(int i = 0; i < T.size(); i++){
        int x = T[i] - 'a';
        auto it = lower_bound(tmp[x].begin(), tmp[x].end(), pre);
        if(it == tmp[x].end()){
            ans += ns - pre + 1;
            ans += tmp[x][0];
            pre = tmp[x][0];
        }else{
            ans += *it -pre + 1;
            pre = *it;
        }
        pre++;
        //cout << " pre " <<  pre << "ans " << ans <<endl;
    }
    cout << ans << endl;
}
