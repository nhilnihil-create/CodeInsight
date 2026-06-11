#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <iomanip>
#define ll long long

using namespace std;

long long MOD = 1000000007;

long long gcd(long long N, long long M){
    while (true){
        if (min(N,M)==0){
            return max(N,M);
        }else if (N>M){
            N%=M;
        }else{
            M%=N;
        }
    }
}

long long lcm(long long N, long long M){
    return N*M/gcd(N,M);
}

int main(){
    ll X;
    cin >> X;

    ll l=lcm(X,360);
    cout << l/X << endl;
}