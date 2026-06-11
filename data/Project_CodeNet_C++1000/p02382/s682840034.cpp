#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> X(n), Y(n);
    for(int i = 0; i < n; i++){
        cin >> X.at(i);
    }
    for(int i = 0; i < n; i++){
        cin >> Y.at(i);
    }

    double d_p1 = 0, d_p2 = 0, d_p3 = 0, d_pp = 0;
    for(int i = 0; i < n; i++){
        int x = X.at(i), y = Y.at(i);
        d_p1 += abs(x - y);
        d_p2 += (x-y) * (x-y);
        d_p3 += abs((x-y) * (x-y) * (x-y));
        d_pp = d_pp < abs(x-y) ? abs(x-y) : d_pp;
    }

    printf("%.6f\n", d_p1);
    printf("%.6f\n", sqrt((double)d_p2));
    printf("%.6f\n", cbrt((double)d_p3));
    printf("%.6f\n", d_pp);

}
