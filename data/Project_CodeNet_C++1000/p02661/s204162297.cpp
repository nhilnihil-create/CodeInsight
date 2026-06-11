#include <bits/stdc++.h>
using namespace std;
#define LL long int
#define ULL unsigned long int
#define LD long double

LL MOD = 1000000007;


int main(){
    LL n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);

    for(int i = 0; i < n; ++i){
        cin >> a[i] >> b[i];
    }

    sort(a.begin(),a.end());
    sort(b.begin(),b.end());

    LL left,right;

    if(n % 2 == 1){
        left = a[n/2];
        right = b[n/2];
    }else{
        left = a[n / 2 - 1] + a[n / 2];
        right = b[n / 2 - 1] + b[n / 2];
    }

    cout << right - left + 1 << endl;

    return 0;
}