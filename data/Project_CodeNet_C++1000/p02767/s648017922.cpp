#include <bits/stdc++.h>
using namespace std;
using ll = long long; //10^19 < 9223372036854775807
#define REP(i,n) for(ll i=0;i<ll(n);i++)

float mean(vector<int> v) {
    int size = v.size();
    float sum = 0;
    for (int i = 0; i < size; i++){
        sum += v[i];
    }
    return sum / size;
}

int main(void)
{
    int N;
    cin >> N;

    vector<int> X(N);
    REP (i, N) {
        cin >> X[i];
    }

    REP (i, N) {
        cin >> X[i];
    }
    sort(X.begin(),X.end());

    int middle1 = ceil(mean(X));
    int middle2 = floor(mean(X));
    int total1 = 0;
    int total2 = 0;
    REP (i, N) {
        total1 += (X[i] - middle1) * (X[i] - middle1);
        total2 += (X[i] - middle2) * (X[i] - middle2);
    }

    cout << min(total1,total2) << endl;

    return 0;
}
