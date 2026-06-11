#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
//void p(vector<int> A){rep(i,A.size()){cout << A[i] << " ";}cout << "\n";}

int main(){
    vector<string> S = {"Sunny","Cloudy","Rainy","Sunny"};
    string s;
    cin >> s;
    rep(i,s.size()){
        if(s == S[i]){
            cout << S[i+1];
          exit(0);
        }
    }
}
