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
    ll N ;
    cin >> N ;
    ll a[N] ;
    ll cnt  = 0 ;
    for(int i = 0; i < N ; i++){
        cin >> a[i] ;
        if(a[i] %2 != 0){
            if(i % 2 == 0){
                cnt++ ;
            }
        }
    }
    cout << cnt << endl;
}