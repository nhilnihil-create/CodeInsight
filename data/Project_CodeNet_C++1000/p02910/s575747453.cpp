#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
//void p(vector<int> A){rep(i,A.size()){cout << A[i] << " ";}cout << "\n";}

int main(){
    string s;
    cin >> s;
    rep(i,s.size()){
        //cout <<i <<  s[i];
        if(i%2 != 0){
            if(s[i] == 'L' || s[i] == 'U' || s[i] == 'D');
            else {cout << "No";exit(0);}
        }
        else{
            if(s[i] == 'R' || s[i] == 'U' || s[i] == 'D');
            else{cout << "No";exit(0);}
        }
    }
    cout << "Yes";
}