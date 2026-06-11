#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
typedef long long ull;
typedef long double ld;
#define inp_arr(name,size) for(int i = 0;i<size;i++)\
cin >> name[i];
#define cepat cin.tie(0);


int main(){
    cepat
    cout.precision(9);
    double w,h,x,y;
    cin >> w >> h >> x >> y;
    cout << w*h/2 << " " << (x==w/2&&y==h/2);

    return 0;
}






