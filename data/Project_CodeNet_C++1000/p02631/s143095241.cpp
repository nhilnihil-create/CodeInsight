#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    int a[N];
    for(int i = 0; i < N; i++){
        cin >> a[i];
    }
    int ALL = a[0];
    for(int i = 1; i < N; i++){
        ALL = ALL^a[i];
    }
    for(int i = 0; i < N; i++){
        int hoge = ALL^a[i];
        cout << hoge << " ";
    }
    cout << endl;
}