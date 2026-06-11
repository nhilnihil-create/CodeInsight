#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll mod = 1e9+7;

int main(){
    int n,m;
    cin >> n >> m;
    map<int,bool> mp;
    int ac = 0;
    map<int,int> wa;
    for(int i = 0; i < m; i++){
        int p;
        string s;
        cin >> p >> s;
        if(s == "AC" && !mp[p]){
            mp[p] = true;
            ac++;
        } else if (s == "WA" && !mp[p]) {
            wa[p]++;
        }
    }
    int WA = 0;
    for(auto p:mp){
        if(p.second) WA += wa[p.first];
    }
    cout << ac << " " << WA << endl;
    return 0;
}