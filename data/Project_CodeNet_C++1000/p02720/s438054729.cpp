#include<bits/stdc++.h>
#define ll long long
#define P pair<ll, ll>
using namespace std;

ll mod = 1e9 + 7;

int main(){
    vector<vector<ll>> vec(10, vector<ll>(10));
    for(int j=0;j<10;j++) vec[0][j] = 1;
    for(int i=1;i<10;i++){
        for(int j=0;j<10;j++){
            if(j==0) vec[i][j] = vec[i-1][j] + vec[i-1][j+1];
            else if(j==9) vec[i][j] = vec[i-1][j] + vec[i-1][j-1];
            else vec[i][j] = vec[i-1][j-1] + vec[i-1][j] + vec[i-1][j+1];
        }
    }

    /*for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            cout << vec[i][j] << " ";
        }cout<< endl;
    }*/


    int k;
    cin >> k;
    vector<ll>ans;
    ll sum = 0;
    int i, j;
    bool end = false;
    for(i=0;i<10;i++){
        for(j=0;j<10;j++){
            if(i != 0 && j == 0) continue;
            if(sum + vec[i][j] <= k) sum += vec[i][j];
            else{
                end = true;
                break;
            }
        }
        if(end) break;
    }
    ans.push_back(j);
    while(i > 0){
        if(j > 0){  
            if(k < sum + vec[i-1][j-1]){
                j--;
            }else if(k < sum + vec[i-1][j-1] + vec[i-1][j]){
                sum += vec[i-1][j-1];
            }else{
                sum += vec[i-1][j-1] + vec[i-1][j];
                j++;
            }
        }else{
            if(k < sum + vec[i-1][j]){
            }else{
                sum += vec[i-1][j];
                j++;
            }
        }
        i--;
        ans.push_back(j);
    }
    
    for(auto v:ans) cout << v;
    cout << endl;
}