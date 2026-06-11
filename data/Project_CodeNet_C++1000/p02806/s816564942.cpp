#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
typedef long long ll;
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<pair<string, ll> > s(n);
    for(int i = 0;i < n;i++){
        string t;
        ll n;
        cin >> t >> n;
        s[i] = make_pair(t,n);
    }
    string key;
    cin >> key;
    ll ans = 0;
    bool flag = false;
    for(int i = 0;i < n;i++){
        if(flag){
            ans += s[i].second;
        }
        if(s[i].first == key){
            flag = true;
        }
    }
    cout << ans << endl;
}
