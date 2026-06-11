#include <iostream>
#include <string>
#include <array>
#include <algorithm>
#include <vector>
#define int long long
using namespace std;

signed main() {
    int A,B,M;
    int a[100001],b[100001],x[100001],y[100001],c[100001];
    int Min = 10000000;

    cin >> A >> B >> M;

    
    for(int i = 0; i < A; i ++){
        cin >> a[i];
    }
    for(int i = 0; i < B; i ++){
        cin >> b[i];
    }
    for(int i = 0; i < M; i ++){
        cin >> x[i] >> y[i] >> c[i];
    }


    

    for(int i = 0; i < M; i ++){
        Min = min(a[x[i]-1] + b[y[i]-1] -c[i],Min);
    }

    sort(a,a+A);
    sort(b,b+B);

    Min = min(Min,a[0]+b[0]);

    cout << Min;
    return 0;
}