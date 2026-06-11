// 15:44-15:53, 2WA
#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main(){
    int N;
    cin >> N;

    int X = 0;
    while((int)(X * 1.08) != N){
        if (X == N){
            cout << ":(" << endl;
            return 0;
        }
        X++;
    }

    cout << X << endl;

    return 0;
}