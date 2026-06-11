#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;
using namespace std;
using P = pair<int,int>;

int main(){
    int a, b;
    cin >> a >> b;
    if(a < b){
        for(int i = 0; i < b; i++){
            cout << a;
        }
        cout << endl;
    }
    else{
        for(int i = 0; i < a; i++){
            cout << b;
        }
        cout << endl;
    }
   return 0;
}