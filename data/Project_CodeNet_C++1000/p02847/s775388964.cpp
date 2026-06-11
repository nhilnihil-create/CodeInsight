#include <bits/stdc++.h>

using namespace std;
#define all(a)a.begin(),a.end()
using ll=long long;
const int INF = 1<<30;
const ll INFll =1LL<<62;
const int mod= int(1e9)+7;
using P = pair<ll,ll>;
using ld=long double;

int main(){
    string day[7]={"MON","TUE","WED","THU","FRI","SAT","SUN"};
    string s;
    cin >>s;
    ll ans;
    for (int i = 0; i < 7; ++i) {
        if(s==day[i]){
            ans=i;
        }
    }
    if(6-ans==0){
        cout <<7<<endl;
    }
    else {
        cout << 6 - ans << endl;
    }
    return 0;
}