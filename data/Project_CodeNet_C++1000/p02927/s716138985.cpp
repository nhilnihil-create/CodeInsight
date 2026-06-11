//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <stdio.h>
#include <complex>
#include <iomanip>
#include <queue>
//定数
#define MOD 1000000007
//マクロ
#define rep(i,n)    for(int (i)=0;(i)<(n);(i)++)
#define reprev(i,n) for(int (i)=(n-1);(i)>=0;(i)--)
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))

#define vsort(v) sort((v).begin(), (v).end());

typedef unsigned long long int ull;
typedef long long lint;

using namespace std;




int main(){
    int M, D;
    int d10, d1;
    int count=0;

    //入力
    cin >> M >> D;
    

    for(int i=2; i <= D; i++) {
        d10 = i/10;
        d1  = i%10;
        if(d10>=2 && d1>=2 && d1*d10 <= M) count++;
    }
    cout << count << endl;
    

    return 0;
}