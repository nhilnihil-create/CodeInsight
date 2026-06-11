#include <algorithm>
#include <iostream>
#include <vector>
#include <functional>
#include <string>
#include <cmath>  //sqrt 
#include <iomanip> //setprecision
using namespace std;

int main(){
    int n ; cin >> n;
    int m;
    int count=0;
    int odd=0;
    while(n){
        m=n;
        count=0;
        while(m){
            count++;
            m /= 10;
        };
        if(count%2==1) odd++;
        n--;
    };
    cout << odd << endl;
    return 0;
}