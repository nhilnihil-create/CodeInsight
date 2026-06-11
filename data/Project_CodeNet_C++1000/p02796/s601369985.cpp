#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
    ll N;
    cin >> N;
    vector<pair<ll,ll>> R;
    for(int i=0;i<N;i++){
        ll X,L;
        cin >> X >> L;
        R.emplace_back(X-L,X+L);
    }
    sort(R.begin(),R.end());
    set<ll> removed;
  
    for(int i=0;i<N;i++){
        if(removed.find(i) != removed.end()){
            continue;
        }
        ll t= i+1;
        while(t<N && R[t].first < R[i].second){
            if(removed.find(t) != removed.end()){
                t++;
                continue;
            }
            if(R[i].second < R[t].second){
                removed.insert(t);
                t++;
            }else{
                removed.insert(i);
                break;
            }
        }
    }
    cout <<N -removed.size() << endl;

    return 0;
}