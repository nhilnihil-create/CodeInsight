#include <bits/stdc++.h>

using namespace std;

int main(){
    int x;
    cin >> x;
    // if (x < 600) {
    //     cout << 8;
    // }
    // else if (x < 800){
    //     cout << 7;
    // }
    // else if (x < 1000){
    //     cout << 6;
    // }
    // else if (x < 1200){
    //     cout << 5;
    // }
    // else if (x < 1400){
    //     cout << 4;
    // }
    // else if (x < 1600){
    //     cout << 3;
    // }
    // else if (x < 1800){
    //     cout << 2;
    // }
    // else{
    //     cout << 1;
    // }
    cout<<8-((x-400)/200);
    return 0;
}