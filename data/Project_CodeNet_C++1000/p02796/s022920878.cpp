#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n;
    cin >> n;

    vector<pair<ll, ll> > p;
    for(int i = 0; i < n ; i++){
        ll t, k;
        cin >> t >> k;
        p.push_back(make_pair(k, t));
    }
  
    vector<pair<int, int> > dis;
    for(int i = 0; i < n; i++){
        ll k = p[i].second + p[i].first;
        ll t = p[i].second - p[i].first;
        dis.push_back(make_pair(k, t));
    }

    sort(dis.begin(), dis.end());

    int cou = 0;
    ll now = -10e9 - 9;
    for(int i = 0; i < dis.size(); i++){
        if(now <= dis[i].second){
            cou++;
            now = dis[i].first;
        }
    }

    cout << cou << endl;
}