#include<bits/stdc++.h>

using namespace std;

typedef pair<long,long> P;

int main(){
    int N;
    const int Nmax = 100000;
    P data[Nmax];
    long X,L;

    cin >> N;
    for(int i = 0;i < N;i++){
        cin >> X >> L;
        data[i] = P(X + L,X - L);
    }
    sort(data,data + N);

    long m = -LONG_MAX;
    int ans = 0;
    for(int i = 0;i < N;i++){
        if(data[i].second >= m){
            ans++;
            m = data[i].first;
        }
    }

    cout << ans << endl;

    return 0;
 }