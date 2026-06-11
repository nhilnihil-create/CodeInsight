#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define rep(i,n) for(ll i = 0; i < (ll)(n); i++)
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const ll INF = 1LL << 60;
int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    map<int,int> mp;
    rep(i,n) {
        cin >> a[i];
        mp[a[i]]++;
        if(mp.size()>3){
            cout << "No" << endl;
            return 0;
        }
    }
    if(mp.size()==1) {
        if(mp[0]==n) cout << "Yes" << endl;
        else cout << "No" << endl;
        return 0;
    }
    if(n%3!=0){
        cout << "No" << endl;
    }else{
        if(mp.size()==3){
            vector<int> key;
            for(auto p : mp){
                key.push_back(p.first);
                if(p.second!=n/3){
                    cout << "No" << endl;
                    return 0;
                }
            }
            if((key[0]^key[1])!=key[2]){
                cout << "No" << endl;
                return 0;
            }
            cout << "Yes" << endl;
        }else if(mp.size()==2){
            for(auto p: mp){
                if(p.first == 0 && p.second==n/3) continue;
                else if(p.first >0 && p.second==n*2/3) continue;
                else{
                    cout << "No" << endl;
                    return 0;
                }
            }
            cout << "Yes" << endl;
        }       
    }
    
    return 0;
}