#include <string>
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
#define rep(i,n) for(int i = 0; i < (n); i++)
#define INF 1000000000

using namespace std;


int main()
{
    int n;
    int min = INF, ans = 0 ;
    cin >> n;
    rep(i,n){
        int p;
        cin >> p;
        if(p < min){
            ans++;
            min = p;
        }
    }
    cout << ans << endl;
}