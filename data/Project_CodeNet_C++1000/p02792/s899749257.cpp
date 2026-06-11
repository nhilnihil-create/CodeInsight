#include <iostream>
#include <cmath>
#include <iomanip>
#include <utility>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>

using namespace std;

long long gcd(int x, int y){
    if ( x == 0 ) return y;

    return gcd(y%x, x);
}

long long lcm(int x, int y){
    if ( y == 0 ){
        return x;
    }

    return x*y/gcd(x, y);
}

int min(int a, int b){
    return a > b ? b : a;
}

int max(int a, int b){
    return a > b ? a : b;
}

int main()
{
    cin.sync_with_stdio( false );
    int n;
    cin>>n;

    int m[15][15];
    for (int i=0;i<15;i++)
        for (int j=0;j<15;j++)
            m[i][j] = 0;

    for (int i=1;i<=n;i++){
        int a = i % 10;
        int b = i;

        while ( b >= 10 ){
            b/=10;
        }

        m[a][b]++;
    }

    int res = 0;
    for (int i=1;i<=n;i++){
        int a = i % 10;
        int b = i;

        while ( b >= 10 ){
            b/=10;
        }

        res+=m[b][a];
    }

    cout<<res<<endl;
}
