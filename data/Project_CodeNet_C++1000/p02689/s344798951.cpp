#include <bits/stdc++.h>
#include <cmath>
using namespace std;

int main(){
    int n,h; cin >> n >> h;
    vector<int> hai(n),hei(n);
    for(int i = 0; i < n; i++){
        cin >> hai[i];
        hei[i] = 0;
    }
    int sum = 0;
    int a, b;
    for(int i = 0; i < h; i++){
        cin >> a >> b;
        hei[a -1] = max(hei[a-1], hai[b-1]);
        hei[b-1] = max(hei[b-1], hai[a-1]);
    }
    for(int i = 0; i< n; i++){
        if(hai[i] > hei[i]){
            sum++;
        }
    }

    cout << sum << endl;
}