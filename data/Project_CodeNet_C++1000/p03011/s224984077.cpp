#include <iostream>

using namespace std;

const int maxf = 3;
int f[maxf];

int main()
{
    int mini = 0 , ans;
    for (int i = 0 ; i < 3 ; i++){
        cin >> f[i];
        if (mini <= f[i]){
            mini = f[i];
        }
    }
    if (mini == f[0]){
        ans = f[1] + f[2];
    }else if (mini == f[1]){
        ans = f[0] + f[2];
    }else if (mini == f[2]){
        ans = f[0] + f[1];
    }
    cout << ans;
    return 0;
}
