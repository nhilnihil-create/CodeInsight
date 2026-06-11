#include <bits/stdc++.h>
using namespace std;
#define REP(i, init, n) for(int i = (int)(init); i < (int)(n); i++)

#define vi vector<int>
#define vl vector<long>
#define vvi vector<vector<int>>
#define vvl vector<vector<long>>
#define pint pair<int, int>
#define plong pair<long, long>

int main() {
    int M; 
    cin>>M;
    vector<plong> N;
    long sum_d = 0;
    long keta = 0;
    REP(i, 0, M){
        long d, c;
        cin >> d >> c;
        sum_d += d*c;
        keta += c;
    }
    cout << (sum_d-1) / 9 + keta - 1 << endl;
}