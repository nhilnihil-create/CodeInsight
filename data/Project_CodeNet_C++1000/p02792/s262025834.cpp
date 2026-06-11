#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector <vector<int>> vv(10);
    for(int i = 0; i < 10; i++){
        vv[i] = vector<int>(10,0);
    }
    for(int i = 1; i <= n; i++){
        int currentNumber = i;
        int headNumber = 0;
        int tailNumber = i%10;
        while(currentNumber>0){
            headNumber = currentNumber%10;
            currentNumber/=10;
        }
        //cout <<i <<" "<< headNumber << " " << tailNumber << endl;
        vv[headNumber][tailNumber]++;
    }
    long long ans = 0;
    for(int i = 1; i <= 9; i++){
        for(int j = 1; j <= 9; j++){
            ans += vv[i][j]*vv[j][i];
        }
    }
    cout << ans << endl;
    #if 0
    for(int i = 1; i <= 9; i++){
        for(int j = 1; j <= 9; j++){
            if(i!=j){
                cout << vv[i][j] << " ";
            }
        }
        cout << endl;
    }
    #endif
    return 0;
}