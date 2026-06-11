#include <iostream>
#include <string>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;
int main() {
    int a[6];
    for (int i=0; i<6; i++) {
        cin >> a[i];
    }
    int n;
    cin >> n;
    int x,y;
    for (int i=0; i<n; i++) {
        cin >> x >> y;
        if(x==a[0]){
            if(y==a[1]){
                cout <<a[2];
            }
            if(y==a[2]){
                cout <<a[4];
            }
            if(y==a[3]){
                cout <<a[1];
            }
            if (y==a[4]) {
                cout <<a[3];
            }
        }
        if(x==a[1]){
            if(y==a[0]){
                cout <<a[3];
            }
            if(y==a[2]){
                cout <<a[0];
            }
            if(y==a[3]){
                cout <<a[5];
            }
            if (y==a[5]) {
                cout <<a[2];
            }
        }
        if(x==a[2]){
            if(y==a[1]){
                cout <<a[5];
            }
            if(y==a[5]){
                cout <<a[4];
            }
            if(y==a[4]){
                cout <<a[0];
            }
            if (y==a[0]) {
                cout <<a[1];
            }
        }
        if(x==a[3]){
            if(y==a[1]){
                cout <<a[0];
            }
            if(y==a[0]){
                cout <<a[4];
            }
            if(y==a[4]){
                cout <<a[5];
            }
            if (y==a[5]) {
                cout <<a[1];
            }
        }
        if(x==a[4]){
            if(y==a[2]){
                cout <<a[5];
            }
            if(y==a[5]){
                cout <<a[3];
            }
            if(y==a[3]){
                cout <<a[0];
            }
            if (y==a[0]) {
                cout <<a[2];
            }
        }
        if(x==a[5]){
            if(y==a[2]){
                cout <<a[1];
            }
            if(y==a[4]){
                cout <<a[2];
            }
            if(y==a[1]){
                cout <<a[3];
            }
            if (y==a[3]) {
                cout <<a[4];
            }
        }
        cout << endl;
    }
}

