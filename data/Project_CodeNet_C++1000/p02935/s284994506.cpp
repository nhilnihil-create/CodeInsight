#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, t;
    scanf("%d", &n);
    vector <int> a;
    for(int i = 0; i < n; i++){
        scanf("%d", &t);
        a.push_back(t);
    }
    sort(a.begin(), a.end());
    float start = a[0];
    for(int i = 1; i < n; i++){
        start = (start + a[i]) / 2.;
    }
    printf("%.5f", start);

    return 0;
}
