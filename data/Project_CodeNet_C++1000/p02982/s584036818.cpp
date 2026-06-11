 #include <bits/stdc++.h>
#include <numeric>
using namespace std;
#define ll long long


double calc(int a,int b){
    return abs(a - b) * abs(a - b);
}
int main(){
    int ans = 0;
    int N, D;
    cin >> N >> D;
    vector<vector<int>> X(N, vector<int>(D));
    for (int i = 0; i < N;i++)
    {
        for (int j = 0; j < D;j++)
        {
            cin >> X[i][j];
        }
    }
    for (int i = 0; i < N;i++)
    {
        for (int j = i + 1; j < N;j++)
        {
            double calced = 0;
            for (int k = 0; k < D; k++)
            {
                calced = calced +(double)calc(X[i][k], X[j][k]);
            }
            calced = sqrt(calced);
            if (floor(calced) == calced)
            {
                ans++;
            }
        }
    }
    cout << ans << endl;
}
