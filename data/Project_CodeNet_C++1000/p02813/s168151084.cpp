#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const long long INF = 1LL<<60;

ll GCD(ll x,ll y){
    if(y == 0) return x;
    else return GCD(y,x%y);
}

ll LCM(ll a,ll b){
    return a / GCD(a,b) * b;
}

const int MOD = 1000000007;


int main() {
    int n; cin >> n;
    string a,b;
    for(int i = 0;i < n;i++){
        char e; cin >> e; a+=e;
    }
    for(int i = 0;i < n;i++){
        char e; cin >> e; b+=e;
    }
    string s = a; sort(s.begin(),s.end());
    vector<string> v;
    
    int x = 0,y = 0;
    do{
        v.push_back(s);
    }while(next_permutation(s.begin(),s.end()));
    sort(v.begin(),v.end());
    for(int i = 0;i < v.size();i++){
        if(v[i] == a) x = i;
        if(v[i] == b) y = i;
    }
    cout << abs(x-y);
}
