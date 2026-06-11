#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> hi(n);
    vector<int> count(n);
    int j=0;
    for (int i = 0; i < n; i++){
        cin >> hi.at(i);
    }
    //入力終わり
    for (int i = 0; i < n-1; i++){
        if(hi.at(i) >= hi.at(i+1)){
            count.at(j)++;
        }else{
            j++;
        }
    }
    sort(count.begin(), count.end());//小さい順に並べる
    reverse(count.begin(), count.end());//リバース
    cout << count.at(0) << endl;
} 