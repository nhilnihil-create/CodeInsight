#include <iostream>
#include <cstdlib>
#include <vector>
#include <cmath>
using namespace std;
int main()
{
    int n;
    double m, v, std_dev;
    while(cin >> n){
        if(n == 0){
            break;
        }
        // init
        vector<int> s;
        s.resize(n);
        m = 0.0;
        v = 0.0;
        std_dev = 0.0;
        for (int i=0; i<n; ++i){
            cin >> s[i];
        }
        // find m
        for (int i=0; i<n; ++i){
            m += (double) s[i];
            if (i == n-1){
                m = m / (double) n;
            }
        }
        // find s
        for (int i=0; i<n; ++i){
            v += pow(s[i] - m, 2);
            if (i == n-1){
                v = v / (double) n;
            }
        }
        std_dev = sqrt(v);
        printf("%.8f\n", std_dev);
    }
    return 0;
}

