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
    if(s == "Sunny") cout << "Cloudy" << endl;
    else if(s == "Cloudy") cout << "Rainy" << endl;
    else cout << "Sunny" << endl;
    return 0;
}