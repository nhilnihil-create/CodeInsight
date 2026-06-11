#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,k,s;
    cin >> n >> k >> s;
    if(s == 1000000000){//+1できない分は1にして計算すると超えない
        for(int i = 0; i < k; i++){
            cout << s << " ";
        }
        for(int i = 0; i < n-k; i++){
            cout << 1 << " ";
        }
        cout << endl;
    }else{//+1して表せば、条件を満たす。
        for(int i = 0; i < k; i++){
            cout << s << " ";
        }
        for(int i = 0; i < n-k; i++){
            cout << s+1 << " ";
        }
        cout << endl;
    }
    return 0;
}