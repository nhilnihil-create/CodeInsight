#include<bits/stdc++.h>

#define _GLIBCXX_DEBUG
#define all(v) (v).begin(),(v).end()

using namespace std;

using ll=long long;
using pii=pair<int, int>;
using vi=vector<int>;

const ll INF=1LL<<60;
const ll MOD=1e9+7;

int main(){
    int a, b; cin >> a >> b;
    string s, t;
    for(int i=0; i<b; i++){
        s+=a+'0';
    }
    for(int i=0; i<a; i++){
        t+=b+'0';
    }
    cout << (s<t ? s:t) << endl;
    return 0;
}