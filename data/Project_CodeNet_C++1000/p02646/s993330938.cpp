#include <bits/stdc++.h>
using namespace std;

void Main()
{
    int a, v, b, w, t;
    cin >> a >> v >> b >> w >> t;
    b = abs(b - a);
    if(v <= w){
        cout << "NO" << endl;
        return;
    }
    int xa = v * t;
    int xb = b + w * t;
    if(xb <= xa){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
}

int main(int argc, char **argv)
{
    Main();
    return 0;
}
