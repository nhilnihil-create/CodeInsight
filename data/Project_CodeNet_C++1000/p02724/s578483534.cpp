#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
typedef long long ull;
typedef long double ld;
#define inp_arr(name,size) for(int i = 0;i<size;i++)\
cin >> name[i];
#define QUICK cin.tie(0);
#define MOD 1e9+7

int main(){
    QUICK

    int a;
    cin >> a;
    int b = a/500;
    int c = a%500;
    int d = c/5;
    cout << (ull)b*1000+(ull)d*5;

    return 0;
}



