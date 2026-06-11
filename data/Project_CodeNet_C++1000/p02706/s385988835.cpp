#include<algorithm>
#include<cmath>
#include<iostream>
#include<vector>
#include<string>
using namespace std;
typedef long long ll;

#define REP(i, n) for(ll i=0;i<ll(n); i++)

int main(){
    int N, M;
    int count = 0;
    int i;
    cin >> N >> M;
    for(i=0;i<M;i++){
        int ai;
        cin >> ai;
        count += ai;
    }
    if(N - count >= 0){cout << N - count << endl; return 0;}
    else{cout << "-1" << endl;return 0;}

    return 0;
}
