#include <bits/stdc++.h>
using namespace std;
#define LL long int
#define ULL unsigned long int
#define LD long double

LL MOD = 1000000007;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    int sum_or = 0;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
        sum_or = (sum_or ^ a[i]);
    }
    for(int i = 0; i < n; ++i){
        cout << (sum_or ^ a[i]) << " ";
    }

    cout << endl;

    return 0;
}