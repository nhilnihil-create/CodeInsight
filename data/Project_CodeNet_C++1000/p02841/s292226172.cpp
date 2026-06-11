#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
const ll inf = 1e18 + 5;
typedef pair<int, bool> pib;
bool cmp(vector<int> one, vector<int> two){
    for (int i = 0; i < one.size(); i++){
        if (one[i] != two[i]){
            return false;
        }
    }
    return true;
}
int main() {
    int m1,d1,m2,d2; cin >> m1 >> d1 >> m2 >> d2;
    if (m2 == m1){
        cout << 0;
    }
    else{
        cout << 1;
    }
}

