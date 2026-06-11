#include<iostream>
#include<fstream>
#include <cmath>
#include <algorithm>
#include <stack>
#include <vector>
#include <random>
#include <set>
using namespace std;
typedef long long ll;


int main(){
    ll s;
    cin >> s;
    ll x1=1e9,x2=0,y1=1,y2;
    y2 = s/x1;
    if(s%x1){
        y2++;
        x2 = x1 - s%x1;
    }
    cout << 0 << " " << 0 << " ";
    cout << x1 << " " << y1 << " ";
    cout << x2 << " " << y2 << "\n";
}
