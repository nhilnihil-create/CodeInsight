#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    multiset<int> s;
    for (int i=0; i<(1<<n); i++) {
        int a;
        scanf("%d", &a);
        s.insert(a);
    }
    vector<int> cr((1<<n));
    auto it = s.end();
    it--;
    cr[0] = *it;
    s.erase(it);
    int l = 1;
    int ind = 1;
    while (l<=(n)) {
        int k = ind;
        for (int i=0; i<ind; i++) {
            //printf("%d ", cr[i]);
            auto it = s.lower_bound(cr[i]);

            if (it==s.begin()) {
                printf("No\n");
                return 0;
            }
            it--;
            cr[k++] = *it;
            s.erase(it);
        }  
        //printf("\n"); 
        ind = k;
        l++;
    }
    printf("Yes\n");
}