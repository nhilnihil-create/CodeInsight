#include<bits/stdc++.h>

#define _GLIBCXX_DEBUG
#define all(v) (v).begin(),(v).end()

using namespace std;

using ll=long long;
using pii=pair<int, int>;
using vi=vector<int>;
using vii=vector<vector<int>>;

const ll LINF=1LL<<60;
const int INF=1<<29;
const ll MOD=1e9+7;

vector<string> day={"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};

int main(){
    string S; 
    cin >> S;
    int res;
    for(int i=0; i<7; i++){
        if(S == day[i]){
            res=7-i;
        }
    }
    cout << res << endl;
    return 0;
}