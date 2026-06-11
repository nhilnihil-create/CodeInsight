#include <bits/stdc++.h>
using namespace std;
bool isValid(vector<int>&v1,vector<int>&v2){
    int value = 0;
    for(int i = 0; i < v1.size(); i++){
        value += pow(v1[i]-v2[i],2);
    }
    for(int i = 1; i <= (value); i++){
        if((i*i)==value){
            return true;
        }
    }
    return false;
}
int main(){
    int n,d;
    cin >> n >> d;
    vector <vector<int>> x(n,vector<int>(d));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < d; j++){
            cin >> x[i][j];
        }
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = (i+1); j < n; j++){
           if(isValid(x[i],x[j])){
               ans++;
           }
        }
    }
    cout << ans << endl;
    return 0;
}