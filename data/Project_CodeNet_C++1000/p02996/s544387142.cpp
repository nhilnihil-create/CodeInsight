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

int main(){
    int N;
    cin >> N;
    typedef pair<LL,LL> BA;
    vector<BA> vBA(N);
    REP(i,N){
        LL A, B;
        cin >> A >> B;
        vBA[i] = BA(B,A);
    }

    sort(vBA.begin(), vBA.end());

    LL left_time = 0;
    LL pre_B = 0;
    REP(i,N){
        left_time += vBA[i].first - pre_B;
        left_time -= vBA[i].second;
        if(left_time < 0){
            cout << "No" << endl;
            return 0;
        }
        pre_B = vBA[i].first;

    }
    cout << "Yes" << endl;
    return 0;
}