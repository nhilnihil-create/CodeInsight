#include<algorithm>
#include<cmath>
#include<iostream>
#include<vector>
#include<string>
using namespace std;
typedef long long ll;

#define REP(i, n) for(ll i=0;i<ll(n); i++)

int main(){
    string N;
    char n;

    cin >> N;

    n = N[N.length()-1];

    if(     n == '2' ||
            n == '4' ||
            n == '5' ||
            n == '7' ||
            n == '9'){
        cout << "hon" << endl;
        return 0;}
    else if(n == '0' ||
            n == '1' ||
            n == '6' ||
            n == '8'){
        cout << "pon" << endl;
        return 0;}
    else{
        cout << "bon" << endl;
        return 0;}
}
