#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main(void){
    int a,b;
    cin >> a >> b;
    int count = 0;
    while(a>0){
        a = a/b;
        count++;
    }
    cout << count << endl;
}