#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)


int main(){
    int N;
    cin >> N;

    vector<float> v(N);
    rep(i,N) cin >> v.at(i);
    sort(v.begin(),v.end());

    float x;

    rep(i,N-1){
        x = (v.at(i)+v.at(i+1))/2;
        v.at(i+1) = x;
    }

    cout << v.at(N-1) << endl;


}