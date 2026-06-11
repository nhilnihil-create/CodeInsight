#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,sum = 0;
    cin >> n;
    vector<int> ryouri(n);
    for (int i = 0; i < n; i++){
        cin >> ryouri.at(i);
        ryouri.at(i) = ryouri.at(i)-1;
    }
    vector<int> manzoku(n);
    for (int i = 0; i < n; i++){
        cin >> manzoku.at(i);
    }
    vector<int> tuika(n-1);
    for (int i = 0; i < n-1; i++){
        cin >> tuika.at(i);
    }
    //入力終わり
    for (int i = 0; i < n; i++){
        sum += manzoku.at(ryouri.at(i));
        if(i+1 != n){
            if(ryouri.at(i) == ryouri.at(i+1)-1){
                sum += tuika.at(ryouri.at(i));
            }
        }
    }
    cout << sum << endl;
}