#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <vector>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep2(i,s,n) for(int i = (s);i<(int)(n);i++)

int main(){
    int l , r , d;
    cin >> l >> r >> d;
    int sum = 0;
    rep2(i,l,r+1){
        if(i%d == 0)sum++;
        else continue;
    }
    cout << sum << endl;
}