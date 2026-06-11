#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
    int x;
    cin >> x;
    for(int i=-150; i<150; i++){
        for(int j=-150; j <150; j++){
            if (pow(i, 5) - pow(j, 5) == x){
                cout << i << " " << j << endl;
                exit(0);
            }
        }
    }
}