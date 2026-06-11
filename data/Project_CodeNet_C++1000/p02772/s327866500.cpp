#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <map>


#define reps(i,s,n) for(int (i) = (s); (i) < (n); (i)++)
#define rep(i,n) reps(i,0,n)
using namespace std;
using ll = long long;

int main(){
    int n;
    cin >> n;
    int tmp;

    rep(i,n){
        cin >> tmp;
        if(tmp % 2 == 0){
            if(!(tmp % 3 == 0 || tmp % 5 == 0)){
                cout << "DENIED" << endl;
                return 0;
            }
        }
    }

    cout << "APPROVED" << endl;


    return 0;
}