
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
const ll INF = 1LL << 60;

int main(){
    int a, b, c;
    cin >> a >> b >> c;
    if(a==b && a!=c){
        cout << "Yes" << endl;
    }
    else if(c==b && a!=c){
        cout << "Yes" << endl;
    }
    else if(a==c && b!=c){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
}