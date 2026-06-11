//BISMILLAH
#include <bits/stdc++.h>
using namespace std;
int main(){
    
    cout << setprecision(20);
    cout << fixed;
    double x,y,d,rr;
    int n;
    int cnt = 0;
    cin >> n >> d;
    while(n--){
        cin >> x >> y;
        rr = sqrt((x*x) + (y*y));
        if(rr<=d) cnt++;
    }
    cout << cnt << endl;
    return 0;
}