#include <bits/stdc++.h>
#define pb push_back
#define F first
#define S second
using namespace std;
const int maxn = 1e5 + 1;
int main(){
    int x,y;
    cin >> x >> y;
    int pts[300] = {0,300000,200000,100000};
    int sum = 0;
    sum += pts[x] + pts[y];
    if (x == 1 && y == 1){
       sum += 400000;
    }
    cout << sum << endl;



    return 0;
}
