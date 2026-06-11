#include<vector>
#include <iostream>
#include<string>
#include <complex>
#include <algorithm>
#include<string>
#include <map>
#include <utility>

using namespace std;

int main(){

    double w, h;
    cin >> w;
    cin >> h;
    double x, y;
    cin >> x;
    cin >> y;

    cout << double(w)*double(h)/2;

    if(x + x == w && y + y == h){
        cout << " 1" << endl;
    }else{
        cout << " 0" << endl;
    }
    
}