#include <bits/stdc++.h>
using namespace std;


void solve(int A, int B, int H, int M){
    long double rad = M_PI * 2.0 * ((long double)H/12.0 + ((long double)M/60.0)/12.0 - (long double)M/60.0);
    //cout << rad << endl;
    long double rsq = (long double)(A * A + B * B) - (long double)(2.0 * A * B) * cosl(rad);
    //cout << rsq << endl;
    cout << fixed << setprecision(20) << sqrtl(rsq) << endl;
}

int main(){
    int A;
    scanf("%d",&A);
    int B;
    scanf("%d",&B);
    int H;
    scanf("%d",&H);
    int M;
    scanf("%d",&M);
    solve(A, B, H, M);
    return 0;
}
