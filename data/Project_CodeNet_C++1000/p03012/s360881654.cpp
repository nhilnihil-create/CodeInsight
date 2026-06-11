#include <iostream>
#include <stdio.h>
#include <vector> 
#include <math.h> 
using namespace std;
int main(void){
    int n; cin >> n;
    vector<int> v(n);
    int i = 0;
    while (i < n) {
        cin >> v[i];
        i++;
    }
    i = 1;
    int ans = 10e8;
    while(i < n) {
        int S1 = 0;
        int S2 = 0;
        int j = 0;
        while(j < n) {
            if (j <= i) S1 += v[j];
            else S2 += v[j];
            j++;
        }
        i++;
        ans = min(ans, abs(S1-S2));
    }
    cout << ans << endl;
}