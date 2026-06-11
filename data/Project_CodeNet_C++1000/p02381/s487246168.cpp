#include<iostream>
using namespace std;
#include<cmath>

int main() {
        double m, n, a, s[1000];
        for(int j = 0; j < 100; j++) {
                cin >> n;
                if(n == 0) break;
                m = 0;
                a = 0;
                for(int i = 0; i < n; i++) {
                        cin >> s[i];
                        m += s[i];
                }
                m /= n;
                for(int i = 0; i < n; i++) {
                        a += pow(s[i] - m, 2);
                }
                a /= n;
                cout << sqrt(a) << endl;
        }
        return 0;
}