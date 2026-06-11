#include<bits/stdc++.h>
#define ll long long int
#define vll vector<ll>
#define uset unordered_set<string>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n;
    cin >> n;
    
    uset x;
    while(n--){
        string s;
        cin >> s;
        x.insert(s);
    }
    
    cout << x.size() << endl;
    return 0;
}