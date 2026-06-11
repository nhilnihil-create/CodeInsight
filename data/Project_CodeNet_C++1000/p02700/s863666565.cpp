#include<algorithm>
#include<cmath>
#include<iostream>
#include<vector>
#include<string>
using namespace std;
typedef long long ll;

#define REP(i, n) for(ll i=0;i<ll(n); i++)

int main(){
    int hp_1, at_1, hp_2, at_2;
    cin >> hp_1 >> at_1 >> hp_2 >> at_2;
    while(hp_1 > 0 || hp_2 > 0){

        hp_2 -= at_1;
        if(hp_2 <= 0){cout << "Yes" << endl;return 0;}

        hp_1 -= at_2;
        if(hp_1 <= 0){cout << "No"  << endl;return 0;}
    }

    return 0;
}
