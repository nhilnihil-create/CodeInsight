#include<iostream>
#include<set>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<iterator>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int> p(N);
    unordered_map<int, int> pm;
    for (int i = 0; i < N; i++){
        cin >> p.at(i);
        pm[p.at(i)] = i;
    }
    set<int> ps;
    ps.insert(-1);
    ps.insert(pm[N]);
    ps.insert(N);
    set<long long> ps2;
    ps2.insert(1);
    ps2.insert(-pm[N]);
    ps2.insert(-N);
    long long r = 0;
    for (int i = N-1; i > 0; i--){
        auto x = ps.upper_bound(pm[i]);
        auto xm = ps2.upper_bound(-pm[i]);
        auto xp = ps.upper_bound(*x);
        auto xmm = ps2.upper_bound(*xm);
        if(xp != ps.end()){
            r += i * ((pm[i] + *xm) * (*xp - *x));
        }
        if(xmm != ps2.end()){
            r += i * ((-*xm + *xmm) * (*x - pm[i]));
        }
        ps.insert(pm[i]);
        ps2.insert(-pm[i]);
    }
    cout << r << endl;
}
