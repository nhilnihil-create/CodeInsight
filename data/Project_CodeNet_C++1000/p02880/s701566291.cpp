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

int main(){
    int N; cin >> N;
    for(int i=1; i<=9; i++){
        if(N%i == 0 && N/i <= 9){
            cout  << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" <<endl;
    return 0;
}