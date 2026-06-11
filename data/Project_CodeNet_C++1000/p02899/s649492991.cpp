#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
#define cans cout << ans << endl;
#define cyes cout << "Yes" << endl; 
#define cno cout << "No" << endl; 
typedef long long ll;


int main(){
    int n;
    cin >> n;
    map<int,int> mp;
    for(int i=1; i<=n; i++){
        int a;
        cin >> a;
        mp[a] = i;
    }
    for(int i=1; i<=n; i++){
        cout << mp[i] << " ";
    }
    cout << endl;
    return 0;
}