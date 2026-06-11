#define _GLIBCXX_DEBUG
#include <iostream>
using namespace std;

int main(void){
    int n;
    cin >> n;
    int mn = n+1, cnt = 0;
    for(int i=0; i<n; i++){
        int p;
        cin >> p;
        if(p < mn){
            mn = p;
            cnt++;
        }
    }
    cout << cnt << '\n';
    return 0;
}