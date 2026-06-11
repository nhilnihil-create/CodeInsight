#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
using namespace std;

int main(){
    int A,B;
    cin >> A >> B;
    int ans;
    if(A > 9 || B > 9){
        ans = -1;
    }
    else{
        ans = A*B;
    }
    cout << ans << endl;
}
