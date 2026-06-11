#include <algorithm>
#include <cassert>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;

#define rep(i, n) for(ll i = 0; i < n; i++)
#define REP(i, n) for(ll i = 1; i < n + 1; i++)
#define PI 3.14159265359
#define EPS 0.0000000001
#define MOD 1000000007
//cout << std::fixed << std::setprecision(15) << y << endl;


int main(){
    ll N;
    cin >> N;

    ll maxNum = 0;
    ll maxA = -1;
    ll secondA = -2;
    ll A[N];
    rep(i, N){
        cin >> A[i];
        if(A[i] > maxA){
            secondA = maxA;
            maxA = A[i];
            maxNum = 1;
        }else if(A[i] == maxA){
            maxNum++;
        }else if(A[i] > secondA){
            secondA = A[i];
        }
    }

    rep(i, N){
        if(A[i] == maxA){
            if(maxNum > 1){
                cout << maxA << endl;
            }else{
                cout << secondA << endl;
            }
        }else{
            cout << maxA << endl;
        }
    }

    return 0;
}