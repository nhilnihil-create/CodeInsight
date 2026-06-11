#include <bits/stdc++.h>
using namespace std;
int main(){
    long double t;
    int n;
    cin >>n;
    long double ans = 0;
    for(int i = 0; i <n ; ++i){
            cin >>t;
            ans= ans + 1/t;
    }
    ans = 1/ans;
    cout<< setprecision (16) <<ans ;

}