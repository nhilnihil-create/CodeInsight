#include <bits/stdc++.h>
#include <vector>
#include <queue>
#include <map>
#include <iostream>
#include <iomanip>
using namespace std;
typedef long long LL;
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
template<class T>
inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}

int main(){
    int N;
    cin >> N;
    vector<LL> A(N);
    map<LL, LL> addAdic;
    map<LL, LL> subAdic;
    REP(i, N){
        cin >> A[i];

        LL addA = A[i] + i + 1;
        LL subA = i + 1 - A[i]; 
        if(addAdic.count(addA) == 0){
            addAdic[addA] = 1;
        }else{
            addAdic[addA]++;
        }

        if(subAdic.count(subA) == 0){
            subAdic[subA] = 1;
        }else{
            subAdic[subA]++;
        }

    }

    LL count = 0;
    for(auto itr = addAdic.begin(); itr!=addAdic.end(); itr++){
        LL key = itr->first;
        LL value = itr->second;
        if(subAdic.count(key) == 1){
            count += subAdic[key]*value;
        }

    }

    cout << count << endl;
    return 0;
    
}