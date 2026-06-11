#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i,a,b) for (int i = (a); i < (b); i++ )
typedef pair<int,int> P;
typedef long long ll;
const int INF = 100000000;
const double PI=3.14159265358979323846;

int main (){
    int X;
    cin >> X;

    int res = X%100;
    int num = X/100;

    if (res<=num*5) {
        cout << 1 << endl;
    }
    else {
        cout << 0 << endl;
    }


}



