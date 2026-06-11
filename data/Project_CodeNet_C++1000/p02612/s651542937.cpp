#include<bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(),(x).end()

using ll = long long;
using P = pair<int,int>;
using mp =  map<string,int>;

const int MOD = 1e9 + 7;
const int INF = 1001001001;


int main(void){


    int n;
    cin >> n;

    if(n % 1000 == 0){
        cout << 0 << "\n";
    }else{
        cout << 1000 - n%1000 << "\n";
    }

    return 0;
}