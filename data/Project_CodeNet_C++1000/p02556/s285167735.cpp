#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int rumax=0,rdmax = -2000000001,lumax = -2000000001,ldmax = -2000000001;
    int n,dmax=0;
    vector<pair<int,int>> v;
    cin >> n;
    rep(i,n){
        int x,y;
        cin >> x >> y;
        v.push_back({x,y});
        rumax = max(rumax,(x+y));
        rdmax = max(rdmax,(x-y));
        lumax = max(lumax,(y-x));
        ldmax = max(ldmax,(0-x-y));
    }

    for(auto u:v){
        dmax = max(rumax-(u.first+u.second),dmax);
        dmax = max(rdmax+(0-u.first+u.second),dmax);
        dmax = max(lumax+(u.first-u.second),dmax);
        dmax = max(ldmax+(u.first+u.second),dmax);
    }

    cout << dmax << endl;
}
