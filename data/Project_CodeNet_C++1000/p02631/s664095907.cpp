#include<bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(),(x).end()

using ll = long long;
using P = pair<int,int>;
using mp =  map<string,int>;

const int MOD = 1e9 + 7;
const int INF = 1001001001;


int main(){

    int n;
    cin >> n;
    vector<int> a(n);
    int x = 0;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
        x ^= a[i];
    }

    for(int i = 0; i < n; ++i){
        cout << (x ^ a[i]) << " ";
    }
    cout << "\n";

    return 0;
}
