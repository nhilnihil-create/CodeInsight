#include <bits/stdc++.h>
#define int long long
typedef long long ll;
using namespace std;

const ll MAXN = 200000;

ll N, ans=0, tmp=0;
string S, T;
vector<ll> abc[26];
map<ll,ll> MS, MT;
signed main(){
    cin >> S >> T;
    for(int i=0;i<S.size();i++) {
        ll num = S[i]-'a';
        abc[num].push_back(i);
        MS[num]++;
    }
    for(int i=0;i<T.size();i++) {
        ll num = T[i]-'a';
        MT[num]++;
    }
    for(map<ll,ll>::iterator itr=MT.begin();itr!=MT.end();itr++) {
        pair<ll,ll> p = *itr;
        if(p.second>0&&MS[p.first]==0) {
            cout << -1 << endl;
            return 0;
        }
    }
    ll id = 0;
    for(int i=0;i<T.size();i++) {
        ll id1 = lower_bound(abc[T[i]-'a'].begin(), abc[T[i]-'a'].end(), id%S.size())-abc[T[i]-'a'].begin();
        if(id1==abc[T[i]-'a'].end()-abc[T[i]-'a'].begin()) {
            id = ceil((double)id/(double)S.size())*S.size();
            i--;
            //cout << "OK1" << id << endl;
        }
        else {
            id = floor((double)id/(double)S.size())*S.size()+abc[T[i]-'a'][id1]+1;
            //cout << "OK2" << id << endl;
        }
    }
    cout << id << endl;
    return 0;
}