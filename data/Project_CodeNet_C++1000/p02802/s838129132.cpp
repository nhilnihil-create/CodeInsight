#include <string>
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
#define rep(i,n) for(int i = 0; i < (n); i++)
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    vector<bool> isAC(n+1);
    vector<int> WANum(n+1);
    int wrongNum = 0, ansNum = 0;
    rep(i, m){
        int p;
        string s;
        cin >> p >> s;
        if(!isAC[p]){
            if(s == "AC"){
                isAC[p] = true;
                ansNum++;
                wrongNum += WANum[p];
            } 
            else WANum[p]++;
        }
    }
    cout << ansNum << " "<< wrongNum << endl;
}