#include <bits/stdc++.h>
using namespace std;
int main(void){
    int a; cin >> a;
    int min = 3000000,cnt = 0;
    int n;
    for(int i=0;i<a;i++){
        cin >> n;
        if(n < min){
            min = n;
            cnt++;
        }
    }
    cout << cnt << endl;
}