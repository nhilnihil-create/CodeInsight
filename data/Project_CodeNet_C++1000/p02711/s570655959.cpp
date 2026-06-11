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
    cin >> N;
    int i;
    for(i=0;i<N.length();i++){if(N[i] == '7'){cout << "Yes" << endl;return 0;}}

    cout << "No" << endl;
    return 0;
}
