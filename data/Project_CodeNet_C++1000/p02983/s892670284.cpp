#include <iostream>
#include <vector>
#include <cmath>
#include <string>
using namespace std;
int main() {
    long long int a,b;
    cin >> a >> b;
    
    long long int ans = 2019;
    for(long long int i=a; i <= min(b, a+2019);i++) {

        for(long long int j=a; j <= min(b,a+2019);j++) {

            if(i==j) continue;
            ans = min(ans, (i*j)%2019);
        }
    }
    cout << ans << endl;
}