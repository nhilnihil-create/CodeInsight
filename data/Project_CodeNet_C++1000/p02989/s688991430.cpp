#include<bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int> d(N+1);
    for(int i = 1; i <= N; ++i) cin >> d[i];
    sort(d.begin(), d.end());
    cout << d[N/2+1] - d[N/2] << endl;
    return 0;
}