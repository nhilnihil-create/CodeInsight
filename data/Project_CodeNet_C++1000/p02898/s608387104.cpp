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
    int n , k;
    cin >> n >> k;
    int sum = 0;
    int h[n];
    rep(i,n){
        cin >> h[i];
        if(h[i] >= k)sum++;
    }
    cout << sum << endl;
}