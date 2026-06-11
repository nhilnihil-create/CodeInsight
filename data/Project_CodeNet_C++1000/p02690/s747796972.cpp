#include <bits/stdc++.h>

using namespace std;

using ll = long long;
int main(void)
{
    int X;
    cin >> X;
    int max = 120;

    vector<vector<ll>> xmap(2*max+1, vector<ll>(2*max+1));

    for(int i = -max; i <= max; i++){
        for(int j = -max; j <= max; j++){
            xmap[max+i][max+j] = pow(i, 5) - pow(j, 5);
        }
    }

    int resA = 0, resB = 0;

    for(int i = -max; i <= max; i++){
        for(int j = -max; j <= max; j++){
            if(X == xmap[max+i][max+j]){
                resA = i;
                resB = j;
                break;
            }
        }
    }

    cout << resA << " " << resB << endl;

    return 0;
}
