#include <bits/stdc++.h>
using namespace std;
int main(){
    long long n;
    cin >> n;
    int x = n/3;
    int y = n/5;
    int z = n/15;
    long long total = 0;
    long long xtotal = 0;
    long long ytotal = 0;
    long long ztotal = 0;
    for(int i = 0; i <= n; i++) total += i;
    for(int i = 0; i <= x; i++) xtotal += 3*i;
    for(int i = 0; i <= y; i++) ytotal += 5*i;
    for(int i = 0; i <= z; i++) ztotal += 15*i;

    //cout << x << " " << total << " " << xtotal << " " << ytotal << " " << ztotal << endl;

    cout << total-xtotal-ytotal+ztotal << endl;  
} 
