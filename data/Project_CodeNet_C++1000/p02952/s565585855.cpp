#include<stdio.h>
#include<iostream>

using namespace std;

int N;
int main() {
    cin >> N;
    int ans = 0;
    for(int i=1;i<N+1;i++){
        int cnt = 0;
        int tmp = i;
        while(tmp) {
            tmp /= 10;
            cnt++;
        }
        if(cnt%2) ans++;
    }
    cout << ans << endl;
    return 0;
}