#include <bits/stdc++.h>
#include <iostream>
#include <string>

using namespace std;
int main(){
    int N,M;
    cin >> N >> M;
    while(M--){
        int next;
        cin >> next;
        N -= next;
        if(N < 0){
            cout << -1 << endl;
            return 0;
        }
    }
    cout << N << endl;
}
