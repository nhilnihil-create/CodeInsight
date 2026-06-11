#include<bits/stdc++.h>
using namespace std;
auto ____ = [] () {ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0); };
typedef int_fast64_t LL;
const int_fast32_t MAXN = 3e5+7;
int_fast32_t n,A[MAXN],height[MAXN],F[MAXN];
int main(){
    ____();
    cin >> n;
    for(int i = 1; i <= n; i++){
        int tp;
        cin >> tp;
        A[tp]++;
    }
    for(int i = 1; i <= n; i++) height[A[i]]++;
    LL LS = 0, R = n - height[0];
    for(int h = 1; h <= n; h++){
        F[h] = LS/h+R;
        R -= height[h];
        LS += height[h] * h;
    }
    int h = n;
    for(int i = 1; i <= n; i++){
        while(h>0&&F[h]<i) h--;
        cout << h << endl;
    }
    return 0;
}