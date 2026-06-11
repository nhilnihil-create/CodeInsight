#include<stdio.h>
#include<iostream>

using namespace std;

int N;
int main() {
    cin >> N;
    int cnt = 0;
    for(int i=1;i<=N;i++){
        int x;
        cin >> x;
        if( x != i ) cnt++;
    }
    cout << (cnt <= 2 ? "YES": "NO") << endl; 
    return 0;
}
