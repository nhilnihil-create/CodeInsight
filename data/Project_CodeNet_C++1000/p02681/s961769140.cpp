#include <bits/stdc++.h>
using namespace std;

int main(){
    string a, b;
    cin >> a >> b;
    int size = a.length();
    int i;
    int cnt = 0;
    for (i = 0; i < size; i++){
        if (a[i] == b[i]) {
            cnt++;
        }
    }
    if(cnt == size){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
}
