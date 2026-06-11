#include <bits/stdc++.h>
#define rep0(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i <= (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef tuple<string, int, int> TU;
typedef tuple<int, int, int> TI;

int main()
{
    int W,H,x,y;
    cin >> W >> H >> x >> y;
    cout << (double)W*H/2  << " ";
    if(x==(double)W/2&&y==(double)H/2){
        cout << 1 << endl;
    }else{
        cout << 0 << endl;
    }
}
