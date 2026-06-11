#include <iostream>
#include <bits/stdc++.h>
const int Size = 200005;
long long Arr1[Size], Arr2[Size];
using namespace std;
int main()
{
    long long N,M,K;
    cin >> N >> M >> K;
    vector <long long> cumm1, cumm2;
    cumm1.push_back(0); cumm2.push_back(0);
    for (int i = 1; i <= N; i++){
        cin >> Arr1[i];
        cumm1.push_back(cumm1[i-1] + Arr1[i]);
    }
    for (int i = 1; i <= M; i++){
        cin >> Arr2[i];
        cumm2.push_back(cumm2[i-1] + Arr2[i]);
    }
    long long sum = 0;
    for (long long i = 0; i <= N; i++){
        if (K >= cumm1[i]){
            auto upper = upper_bound(cumm2.begin(), cumm2.end(), (K - cumm1[i]));
            long long idx = (upper - cumm2.begin()) - 1;
            sum = max(sum, idx + i);
        }
    }
    cout << sum ;
}
