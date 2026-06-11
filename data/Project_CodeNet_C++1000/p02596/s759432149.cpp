#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using namespace std;

int main(){
    int k;
    cin >> k;
    int cnt = 0;
    for (int i = 1; i < 1e7;i++)
    {
        cnt = (cnt*10+7) % k;
        if(cnt == 0){
            cout << i << endl;
            return 0;
        }
    }
    cout << "-1" << endl;

    return 0;
}