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

int n;
vector <int> tree(400005, 0);

int query(int a){
    int res = 0;
    for (;a>0;a-=a&-a){
        res+=tree[a];
    }

    return res;
}

void update(int a){
    for (;a<=200000;a+=a&-a){
        tree[a]++;
    }
}

int main()
{
    cin.sync_with_stdio( false );
    cin>>n;

    int res = 0;
    for (int i=0;i<n;i++){
        int a;
        cin>>a;

        if ( i == 0 ){
            update(a);
            res++;
        }else{
            update(a);
            if ( query(a) - 1 == 0 ){
                res++;
            }
        }
    }

    cout<<res<<endl;
}
