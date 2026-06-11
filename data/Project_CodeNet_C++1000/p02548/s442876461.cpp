#include <bits/stdc++.h>
using namespace std;
//vector<vector<int>> a(5, vector<int>(5, 0)) 5*5-0
int main(){
    long long int n;
    cin >> n;
    long long int res = 0;

    for(long long int a = 1; a < n; a++){
        res += (n - 1) / a;
    }

    /*for(long long int i = 1; i < n; i++){// c = i;   
        for(long long int j = 1; j*j <= n - i; j++){
            if((n - i)%j == 0){
                if(j == (n - i) / j){
                    res = res + 1;
                }else{
                    res = res + 2;
                }
            }
        }
    }*/
    cout << res << endl;
}