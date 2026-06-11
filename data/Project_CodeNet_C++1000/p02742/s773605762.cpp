#include <bits/stdc++.h>
using namespace std;
int main(){
    int h, w;
    cin >> h >> w;
    if(h==1 || w==1){
        cout << "1\n";
        exit(0);
    }
    int64_t res = (int64_t)h*w;
    if(res%2 != 0)
        res++;
    res /= 2;
    cout << res << '\n';
    return 0;
}
