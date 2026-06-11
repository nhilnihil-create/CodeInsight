#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (long long i = 0; i < (int)(n); i++)



int main() {
    int n;

    cin >> n;

    for(int i=1; i<=50000; i++){
        int val = 0;
        val = i*1.08;
        if(n == val){
        cout << i;
        return 0;
        }

    }

    cout << ":(";
}