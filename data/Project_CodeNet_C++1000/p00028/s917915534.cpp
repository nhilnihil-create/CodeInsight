#include <math.h>
#include <ctype.h>
#include <bits/stdc++.h>
using namespace std;
#define FOR(i, a, n) for (int i = a; i < n; i++)
#define REP(i, n) for(int i = 0; i < n; i++)
struct omt{omt(){ios::sync_with_stdio(false);cin.tie(0);}}star;

int main(){
    int n;
    map<int, int> mp;

    while(cin >> n){
        mp[n]++;
    }
    
    int ma = 0;
    vector<int> A;
    for(auto x : mp){
        if(x.second > ma){
            A.clear();
            ma = x.second;
            A.push_back(x.first);
        }else if(x.second == ma){
            A.push_back(x.first);
        }
    }
    sort(A.begin(), A.end());
    for(auto x : A) cout << x << endl;


    return 0;
}
