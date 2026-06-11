#include "bits/stdc++.h"
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll =long long;
using P =pair<int,int>;

int main(){
    string s;
    cin >> s;
    vector <string> day;
    day.push_back("SUN");
    day.push_back("MON");
    day.push_back("TUE");
    day.push_back("WED");
    day.push_back("THU");
    day.push_back("FRI");
    day.push_back("SAT");

    int ans;
    rep(i,7){
        if (s==day[i]){
            ans=7-i;
        }
    }
    cout << ans << endl;
    

    return 0;
}