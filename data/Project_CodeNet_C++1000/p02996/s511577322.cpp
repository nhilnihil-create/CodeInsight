#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n;
    cin >> n;
    vector<pair<ll,ll>> v(n);
    for(int i = 0;i < n;i++){
        cin >> v[i].second >> v[i].first; //締め切り、かかる時間
    }
    sort(v.begin(),v.end());
    bool j = true;

    ll time = 0;
    for(int i = 0;i < n;i++){
        time += v[i].second;
        if(time > v[i].first){
            j = false;
            break;
        }
    }

    if(j){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
}