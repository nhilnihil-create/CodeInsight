#include <bits/stdc++.h>
using namespace std;

int main(){
    long long int h, w;
    cin >> h >> w;
    //vector<vector<int>> a(h, vector<int>(w));
    long long int sum = h*w;

    if(h == 1 || w == 1){
        cout << 1 << endl;
    }else{
        if(sum % 2 == 1){
            cout << sum / 2 + 1 << endl;
        }else{
            cout << sum / 2 << endl;
        }
    }   
}