#include <bits/stdc++.h>
using namespace std;

int main() {
    int h,w,a,b;
    cin >> h >> w >> a >> b;
    for(int i=0;i<b;i++){
        for(int j=0;j<a;j++){
            cout << '0';
        }
        for(int j=0;j<w-a;j++){
            cout << '1';
        }
        cout << endl;
    }
    for(int i=0;i<h-b;i++){
        for(int j=0;j<a;j++){
            cout << '1';
        }
        for(int j=0;j<w-a;j++){
            cout << '0';
        }
        cout << endl;
    }
}