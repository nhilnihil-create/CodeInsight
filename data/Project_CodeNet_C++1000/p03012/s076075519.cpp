#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <climits> // FOO_MAX, FOO_MIN
#include <cmath> 
#include <cstdlib> // abs(int)
#include <numeric>

#define roundup(n,d) ( ((n) + ((d)-1)) / (d) )
#define ll long long
#define assign_max(into, compared) (into = max((into), (compared)))
#define assign_min(into, compared) (into = min((into), (compared)))

using namespace std;

int main(void){
    int N;
    cin >> N;
    vector<int> w(N);
    for(int i = 0;i < N;i++){
        cin >> w[i];
    }

    int S1 = accumulate(w.begin(),w.end(),0);
    int S2 = 0;
    int ans = abs(S1 - S2);
    for(int i = 0;i < N;i++){
        S1 -= w[i];
        S2 += w[i];
        assign_min(ans,abs(S1-S2));
    }

    cout << ans << endl;
}