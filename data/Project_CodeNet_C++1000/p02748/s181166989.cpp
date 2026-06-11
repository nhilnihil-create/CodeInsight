#include <algorithm>
#include <iostream>
#include <vector>
#include <numeric>
#include <string>
#include <stdio.h>
#include <set>
#include <cmath>
#include <iomanip>
using namespace std;
 
int main(){
    int A, B, M;
    int ans = 1000000;
    int x, y, c;
    int a_min = 100000;
    int b_min = 100000;
    cin >> A >> B >> M;
    vector<int> a(A);
    vector<int> b(B);
    for (int i=0; i<A; i++){
        cin >> a[i];
        a_min = min(a[i], a_min);
    }
    for (int i=0; i<B; i++){
        cin >> b[i];
        b_min = min(b[i], b_min);
    }
    for (int i=0; i<M; i++){
        cin >> x >> y >> c;
        ans = min(ans, a[x-1]+b[y-1]-c);
    }
    ans = min(ans, a_min+b_min);
    cout << ans << endl;
    return 0;
}