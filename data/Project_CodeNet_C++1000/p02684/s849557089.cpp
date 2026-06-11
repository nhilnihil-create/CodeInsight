#include<iostream>
#include<vector>
using namespace std;
#define MAX 200000

int main() {
    int n;
    vector<int> a(MAX+10), reach(MAX+10, -1);
    long long k;

    scanf("%d", &n);
    scanf("%ld", &k);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
     
    long long cnt = 0;
    int pos = 1;
    while (true) {
        if (reach[pos] !=-1) break;
        if (k == cnt) {
            printf("%d\n", pos);
            return 0;
        }
        reach[pos]=cnt;
        pos=a[pos];
        cnt++;
    }

    k -= reach[pos];
    cnt -= reach[pos];
    k %= cnt;
    for (int i = 0; i < k; i++) pos=a[pos];

    printf("%d\n", pos);
}