#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(int A, int B){
    int ans = -1;
    for(int x = 1; x <= 10000; x++){
        if(floor((double)x*0.08) == A && floor((double)x*0.10) == B){
            ans = x;
            break;
        }
    }
    cout << ans << endl;
    return;
}

int main(){
    int A;
    scanf("%id",&A);
    int B;
    scanf("%id",&B);
    solve(A, B);
    return 0;
}
