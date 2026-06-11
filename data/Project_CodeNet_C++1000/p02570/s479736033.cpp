#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <cmath>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
int mod = (int) 1e9 + 7;
int main(){
    long D , T  , S ;
    cin >> D >> T >> S ;
    if(T * S >= D){
         cout << "Yes" << endl;
         
    }else{
         cout << "No" << endl;
    }
    return 0;
}

