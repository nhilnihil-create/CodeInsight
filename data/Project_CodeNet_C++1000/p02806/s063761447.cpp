#include <bits/stdc++.h>
#include <stdio.h>
#include <math.h>
using namespace std;
using vi = vector<int>;
using vll = vector<long long int>;
using vvi = vector<vector<int>>;
using vvll = vector<vector<long long int>>;
using ll = long long int;

int main(){
    ll N; cin >> N;
    vector<string> s(N); vi t(N);
    for(int i=0; i<N; i++){
        cin >> s[i] >> t[i];
    }
    string X; cin >> X;
    bool k = false;
    ll sum = 0;
    for(int i=0; i<N; i++){
        if(s[i] == X){
            k = true;
        }
        else if(k == true){
            sum += t[i];
        }
    }
    cout << sum;
}