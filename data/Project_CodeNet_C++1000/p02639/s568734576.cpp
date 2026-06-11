#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> a(5);
    for(int i = 0; i < 5; i++){
        cin >> a[i];
    }
    int answer = 0;
    for(int i = 0; i < 5; i++){
        if(a[i] == 0){
            answer = i+1;
            break;
        }
    }
    cout << answer;
}