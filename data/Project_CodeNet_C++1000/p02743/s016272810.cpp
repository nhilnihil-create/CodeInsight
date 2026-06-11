#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;
using ll = long long ;
const int INF = 1001001001;

int main() {

    ll a,b,c ;
    cin >> a >> b >> c;

    if(c-a-b<0){
      cout << "No" << endl ;
    }else{
        if((4*a*b)<(c-a-b)*(c-a-b))
          cout << "Yes" << endl ;
        else 
          cout << "No" << endl ;          
    }
        return 0; 
}