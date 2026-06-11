#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n) ; ++i)
using namespace std;
using ll = long long ;
using P = pair<int, int> ;
#define PI 3.14159265358979323846264338327950
int main () {
    int N ;
    cin >> N ;
    vector<int> vec(N);
    rep(i,N){
        cin >> vec[i];
    }
    bool acc = true;
    rep(i,N){
        if(vec[i] % 2 == 0){
            if (vec[i] % 3 != 0 && vec[i] % 5 != 0){
                acc = false;
            }
        }
    }
    if (acc){
        cout << "APPROVED" << endl;
    }
    else {cout << "DENIED" << endl;}
}

