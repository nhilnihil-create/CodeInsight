#include <bits/stdc++.h>
using namespace std;

int main(){
    float H, W, N;
    cin >> H >> W >> N;

    cout << ceil(N/max(H, W)) << endl;
}