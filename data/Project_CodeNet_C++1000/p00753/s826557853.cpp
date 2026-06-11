#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int pt[4000000];

int main() {
    vector<int> ps(1, 2);
    for(int i=3; i<4000000; i+=2) if(pt[i]==0) {
        ps.push_back(i);
        if(i<10000) for(int j=i*i; j<4000000; j+=i) pt[j] = i;
    }
    for(;;) {
        int n;
        scanf("%d", &n);
        if(n==0) return 0;
        const int a1 = upper_bound(ps.begin(), ps.end(), 2*n)-ps.begin();
        const int a2 = upper_bound(ps.begin(), ps.end(), n)-ps.begin();
        printf("%d\n", a1 - a2);
    }
}