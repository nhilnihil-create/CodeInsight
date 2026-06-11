#include<bits/stdc++.h>
using namespace std;

#define _GLIBCXX_DEBUG
#define all(v) (v).begin(),(v).end()

using ll=long long;
using pii=pair<int, int>;
using vi=vector<int>;
using vii=vector<vector<int>>;

const ll LINF=1LL<<60;
const int INF=1<<29;
const ll MOD=1e9+7;

int main(){
    string s; cin >> s;
    bool ans=true;
    for(int i=0; i<s.size(); i++){
        if(i%2 == 0 && s[i] == 'L') ans=false;
        if(i%2 == 1 && s[i] == 'R') ans=false;
    }
    cout << (ans ? "Yes":"No")  << endl;
    return 0;
}