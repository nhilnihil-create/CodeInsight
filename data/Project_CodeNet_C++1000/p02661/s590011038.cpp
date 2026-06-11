#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    long long N;
    cin >> N;

    long long a[300000];
    long long b[300000];

    for(int i = 0; i < N; i++){
        cin >> a[i] >> b[i];
    }

    sort(a, a+N);
    sort(b, b+N);

    long long ans;
    if( N % 2 == 0){
        ans = (b[N/2] + b[N/2 -1])  -  (a[N/2] + a[N/2 -1]) +1;
    }else{
        ans = ( b[N/2]  - a[N/2] ) + 1;
    }

    cout << ans << endl;

}
