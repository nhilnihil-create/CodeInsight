#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <iomanip>
#define ll long long

using namespace std;

long long MOD = 1000000007;

template<typename T>
void cout_vec(vector<T> &vec){
    for(int i=0; i<vec.size(); i++){
        if (i!=0){
            cout << ' ';
        }
        cout << vec[i];
    }
    cout << endl;
}

template<typename T>
void cout_mat(vector<vector<T>  > &mat){
    for(int i=0; i<mat.size(); i++){
        vector<T> vec = mat[i];
        cout_vec(mat[i]);
    }
}

int main(){
    string L;
    cin >> L;
    int x=L.size();

    vector<vector<ll> > dp(x+1,vector<ll>(2,0));
    dp[0][0]=1;
    for(int i=0; i<x; i++){
        if(L[i]=='1'){
            dp[i+1][1]=(dp[i][0]+dp[i][1]*3)%MOD;
            dp[i+1][0]=dp[i][0]*2%MOD;
        }else{
            dp[i+1][1]=dp[i][1]*3%MOD;
            dp[i+1][0]=dp[i][0]%MOD;
        }
    }

    //cout_mat(dp);

    cout << (dp[x][1]+dp[x][0])%MOD << endl;
}