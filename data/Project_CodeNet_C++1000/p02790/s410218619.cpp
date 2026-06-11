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
    int a,b;
    cin>>a>>b;

    string br = "";
    for (int i=0;i<a;i++){
        br+=b + '0';
    }

    string br1 = "";
    for (int i=0;i<b;i++){
        br1+=a + '0';
    }

    vector <string> aa;
    aa.push_back(br);
    aa.push_back(br1);
    sort(aa.begin(), aa.end());
    cout<<aa[0]<<endl;
}
