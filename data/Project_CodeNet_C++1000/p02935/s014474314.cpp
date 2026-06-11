#include <bits/stdc++.h>
using namespace std;


void solve(long long N, std::vector<float> H){
    sort(H.begin(), H.end());
    float x, y, z;
    for(int i = 0; i < N - 1; ++i){
        if(i == 0) x = H.at(i);
        else x = z;
        y = H.at(i+1);
        z = (x + y) / 2;
    }
    cout << z << endl;
}

int main(){
    long long N;
    scanf("%lld",&N);
    std::vector<float> H(N);
    for(int i = 0 ; i < N ; i++){
        scanf("%fd",&H[i]);
    }
    solve(N, std::move(H));
    return 0;
}
