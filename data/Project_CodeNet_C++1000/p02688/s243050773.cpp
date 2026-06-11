#include<algorithm>
#include<cmath>
#include<iostream>
#include<vector>
#include<string>
using namespace std;
typedef long long ll;

#define REP(i, n) for(ll i=0;i<ll(n); i++)

int main(){
    int N, K;
    int d;
    int i, j;

    cin >> N >> K;

    vector<bool> snk (N, 0);


    for(i=0;i<K;i++){
        cin >> d;
        for(j=0;j<d;j++){
            int ai;
            cin >> ai;
            snk[ai-1] = 1;
        }
    }

    cout << count(snk.begin(), snk.end(), 0) << endl;

    return 0;
}
