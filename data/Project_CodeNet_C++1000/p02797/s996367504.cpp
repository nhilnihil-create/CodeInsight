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
    int N, K;
    LL S;
    cin >> N >> K >> S;

    int n = N - (K-1);

    LL val = S/n;
    LL val_last = S/n + S%n;

    int i=0;
    if (val==0){
        while(i<N){
            if(i<K){
                cout << val_last << " ";
            }else{
                cout << val_last + 1 << " ";
            }
            i++;
        }

    }else{
        while(i<N){
            if((i+1)%n==0){
                cout << val_last << " ";
            }else{
                cout << val << " ";
            }
            i++;
        }
    }
    
    return 0;
}