#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

int main(){
    int a,b,m;
    cin >> a >> b >> m;
    vector<int> ref(a),mic(b);
    int minref=100000,minmic=100000;
    rep(i,a) {
        cin >> ref.at(i);
        minref = min(minref,ref.at(i));
    }
    rep(i,b) {
        cin >> mic.at(i);
        minmic = min(minmic,mic.at(i));
    }
    vector< vector <int> > dis(m,vector<int>(3)); 
    rep(i,m) {
        rep(j,3)cin >> dis.at(i).at(j);
        dis.at(i).at(0)--;
        dis.at(i).at(1)--;
    }

    int totalcost = minref + minmic;

    rep(i,m)totalcost = min(totalcost,ref.at(dis.at(i).at(0)) + mic.at(dis.at(i).at(1)) - dis.at(i).at(2));
    
    cout << totalcost << endl;
}