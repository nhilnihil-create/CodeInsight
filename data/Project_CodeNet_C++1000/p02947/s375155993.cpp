#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const long long INF = 1LL << 60;

int main(){
    int N;
    cin >> N;
    map<string, ll> C;
    ll count = 0;

    for(int i=0; i<N; i++) {
        string s;
        cin >> s;
        sort(s.begin(), s.end());
        C[s]++;
    }
    for(auto c:C){
        if(c.second >= 2) {
            count += (c.second * (c.second - 1)) / 2;
        }
    }
    cout << count << endl;
}