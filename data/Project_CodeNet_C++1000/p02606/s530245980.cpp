#include <iostream>
using namespace std;
int main(){
    int R;
    int L;
    int d;
    cin >> L >> R >> d;
    int ans;
    ans = R/d - (L-1)/d;
    cout << ans <<endl;
}

