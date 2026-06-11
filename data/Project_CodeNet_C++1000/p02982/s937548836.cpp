#include <cstdio>
#include <cmath>
#include <limits>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <cstring>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cstdint>
#include <functional>
#define rep(i, s, g) for (i = s; i < g; i++)
using namespace std;
using ll = long long;

const ll mod = 1000000000 + 7; //10^9


bool is_integer(double x){
    return floor(x) == x;
}

int main() {
    int N, D;
    cin >> N >> D;
    vector<vector<double>> X(N, vector<double>(D));
    
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < D; j++)
        {
            cin >> X.at(i).at(j);
        }
    }
    // for (int i = 0; i < N; i++)
    // {
    //     for (int j = 0; j < D; j++)
    //     {
    //         cout << X[i][j] << endl;
    //     }
    // }
    int ans = 0;
    for (int i = 0; i < N - 1; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            double distance = 0;
            for (int k = 0; k < D; k++)
            {
                distance += pow(X[i][k] - X[j][k],2);
                // cout << X[i][k] <<"," << X[j][k] << ","<< distance << endl;
                
            }
            distance = sqrt(distance);
            // cout << "i:" << i << "j:" << j << "disntance:" << distance << endl;
            bool c = is_integer(distance);
            if(c) ans++;
        }
        
    }
    
    cout << ans << endl;
}