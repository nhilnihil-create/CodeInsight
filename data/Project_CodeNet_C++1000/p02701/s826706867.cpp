#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;

int main(){
    int n;
    cin >> n;
    set<string> x;
    for(int i=0; i<n; i++){
        string s;
        cin >> s;
        x.insert(s);
    }
    cout << x.size() << endl;
}