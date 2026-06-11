#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int n;
    cin >> n;
    int a = n%2;
    int b = n/2;
    float ans = ((float)b+(float)a)/(float)n;
    cout << ans << endl;
}