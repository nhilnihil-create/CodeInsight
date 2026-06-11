#include<iostream>
#include<set>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int> p(N);
    for (int i = 0; i < N; i++){
        cin >> p.at(i);
    }
    unordered_map<int, int> pm;
    for (int i = 0; i < N; i++){
        pm[p.at(i)] = i;
    }
    set<long> ps;
    ps.insert(-1);
    ps.insert(pm[N]);
    ps.insert(N);
    long long r = 0;
    for (int i = N-1; i > 0; i--){
        auto x = ps.upper_bound(pm[i]);
        set<long>::iterator xm(x);
        xm--;
        auto xp = ps.upper_bound(*x);
        if(xp != ps.end()){
            r += i * ((pm[i] - *xm) * (*xp - *x));
        }
        if(xm != ps.begin()){
            set<long>::iterator xmm(xm);
            xmm--;
            r += i * ((*xm - *xmm) * (*x - pm[i]));
        }
        ps.insert(pm[i]);
    }
    cout << r << endl;
}

