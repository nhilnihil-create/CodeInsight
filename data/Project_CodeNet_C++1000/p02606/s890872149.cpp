#include<iostream>
#include<vector>
#include <cmath>
#include <map>
#include <set>
#include <algorithm>
#include <string>
using namespace std;
typedef long long ll;
int main(void){
    ll L , R , d ;
    cin >> L >> R >> d ;
    ll cnt = 0 ;
    for(int i = 0 ; i < R - L + 1 ; i++){
        if((L + i) % d == 0 ) cnt++ ;
    }
    cout << cnt << endl;
}