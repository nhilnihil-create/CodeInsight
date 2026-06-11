#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll mod = 1e9+7;

int main(){
    int n;
    cin >> n;
    vector<int> h(n);
    for(int i = 0; i < n; i++) cin >> h[i];
    map<int,bool> mp;
    reverse(h.begin(),h.end());
    for(int i = 0; i < n-1; i++){
        if(h[i+1] <= h[i]) continue;
        else if(h[i+1]-1 == h[i]){
            h[i+1]--;
            mp[i+1] = true;
        }
        else{
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}