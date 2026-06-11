#include <bits/stdc++.h>
using namespace std;

int main (){
    int A,B;
    cin >> A >> B;

    vector <int>multi_table(9);
    for (int i = 0; i < 9; i++){
        multi_table.at(i) = i + 1;
    }
    
    int res1 = -1;
    int res2 = -1;
    for (int i = 0; i < 9; i++){
        if (multi_table.at(i) == A) res1 = A;
    }
    for (int i = 0; i < 9; i++){
        if (multi_table.at(i) == B) res2 = B;
    }
    if (res1 == -1 || res2 == -1){
        cout << -1 << endl;
    }else cout << res1 * res2 << endl;
}