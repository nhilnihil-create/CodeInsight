#include<bits/stdc++.h>
#include <algorithm>
#define rep(i,n) for (int i=0;i<(n);i++)
#define PI 3.14159265358979323846264338327950L
using namespace std;
using P = pair<int,int>;
using ll = long long;
using namespace std;
int main(void){
    int n;
    cin >> n;
    bool bin = false;
    rep(i,10){
        rep(j,10){
            if(n == i*j){bin = true;}
        }
    }
    if(bin){cout << "Yes";}
    else{cout << "No";}
    return 0;
}