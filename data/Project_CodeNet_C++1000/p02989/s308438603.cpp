#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }
    sort(v.begin(), v.end());
    int result = v[v.size()/2] - v[v.size()/2-1];
    printf("%d\n", result);

    return 0;
}