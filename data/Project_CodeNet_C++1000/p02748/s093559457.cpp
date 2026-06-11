#include <bits/stdc++.h>
#include <algorithm>
#include <functional>
using namespace std;

int main(){
    int A, B, M;
    cin >> A >> B >> M;
    int a[A];
    int b[B];

    for(int i=0; i<A; i++){
        cin >> a[i];
    }

    for(int i=0; i<B; i++){
        cin >> b[i];
    }

    int x[M];
    int y[M];
    int c[M];
    
    for(int i=0; i<M; i++){
        cin >> x[i] >> y[i] >> c[i];
    }

    int min_cost = *min_element(a, a+A) + *min_element(b, b+B);
    for(int i=0; i<M; i++){
        int xi = x[i];
        int yi = y[i];
        int ci = c[i];

        int cost = a[xi-1] + b[yi-1] - ci;
        if(min_cost > cost){
            min_cost = cost;
        }
    }

    cout << min_cost << endl;
    return 0;
}