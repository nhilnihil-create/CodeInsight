#include <bits/stdc++.h>
#include <vector>
#include <queue>
#include <set>
#include <iostream>
#include <iomanip>
using namespace std;
typedef long long LL;
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)

LL comb2(LL val);

int main(){
    int N;
    cin >> N;
    vector<string> si(N);
    REP(i,N){
        cin >> si[i];
    }

    REP(i,N){
        string s = si[i];
        sort(s.begin(), s.end());
        si[i] = s; 
    }

    sort(si.begin(), si.end());
    LL count=0;

    string pre = si[0];
    LL tmp_count = 1;
    FOR(i,1,N){
        if(pre==si[i]){
            tmp_count++;
        }else{
            count += comb2(tmp_count);
            tmp_count = 1;
        }
        pre = si[i];
    }
    count += comb2(tmp_count);

    cout << count << endl;
    return 0;
}

LL comb2(LL val){
    return val*(val-1)/(2*1);
}