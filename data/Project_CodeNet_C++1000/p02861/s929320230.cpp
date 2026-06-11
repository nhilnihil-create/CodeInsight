#include <algorithm>
#include <iostream>
#include <vector>
#include <functional>
#include <string>
#include <cmath>  //sqrt 
#include <iomanip> //setprecision

using namespace std;
using p = pair<int,int>;
int main(){
    cout << fixed << setprecision(10);
    int n; cin >> n;
    vector<p> towns(n);
    double ave;
    for (int i = 0; i < n; i++)
    {
        cin >> towns[i].first >> towns[i].second; 
    }
    vector<vector<double>> dis(n,vector<double>(n,0));
    vector<int> perm(n);
    for (int i = 0; i < n; i++)
    {
        perm[i]=i;
        for (int j = i+1; j < n; j++)
        {
            int dx = abs(towns[i].first - towns[j].first);
            int dy = abs(towns[i].second - towns[j].second);
            dis[i][j] = sqrt(dx*dx + dy*dy);
        }
    }
    
    double sum = 0;
    do{ 
        for (int i = 1; i < n; i++)
        {
            sum += dis[perm[i-1]][perm[i]];
        }
    }while(next_permutation(perm.begin(),perm.end()));

    int div = n;
    for (int j = n-1; j > 0; j--)
    {
        div *= j;
    }
    ave = sum*2/div;
    cout << ave <<endl;
    return 0;
}