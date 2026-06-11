#include <iostream>
using namespace std;
int main(){
    int n; cin >> n;
    int nnum = n+1;
    int cnt = 0;
    for(int i = 0; i < n; ++i){
        int a; cin >> a;
        if(a <= nnum){
            nnum = min(nnum,a);
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}