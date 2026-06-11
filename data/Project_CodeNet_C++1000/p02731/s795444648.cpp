#include<bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(){
    double L; 
    cin >> L;

    double volum=0;
    volum=L/3*L/3*L/3;
    printf("%.7f\n", volum);
    return 0;
}