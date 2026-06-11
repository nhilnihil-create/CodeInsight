#include <iostream>
#include <map>
#include <vector>
#include <cmath>
#define int long long
typedef long long ll;
using namespace std;

ll N;
vector<ll> vemp;
map<ll, char> M;

void vecdp(vector<ll> v){
    //for(ll i=0;i<v.size();i++) cout << v[i];
    for(ll i=0;i<v.size();i++) cout << M[v[i]];
    cout << endl;
}

void dfs(ll count, ll id, vector<ll> v){
    if(count==N-1) {
        vecdp(v);
        return;
    }
    ll i=0;
    while(i<=id+1){
        //cout << i;
        v[count+1] = i;
        if(i==id+1) dfs(count+1, id+1, v);
        else dfs(count+1, id, v);
        i++;
    }
    /*
    for(ll i=0;i<=id+1;i++){
        cout << i;
        v[count+1] = i;
        if(i==id+1) dfs(count+1, id+1, v);
        else dfs(count+1, id, v);
    }
    */
}

signed main(){
    cin >> N;
    vemp.resize(N);
    for(ll i=0;i<N;i++) {
        vemp[i] = 0;
        M[i] = 'a'+i;
        //cout << M[i];
    }
    dfs(0, 0, vemp);
}