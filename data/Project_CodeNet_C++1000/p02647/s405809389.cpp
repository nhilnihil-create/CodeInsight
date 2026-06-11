#include <bits/stdc++.h>
using namespace std;

void solve(int n, int k, vector<int>&a){
    
    int needed = (log(n) + 1.0)/log(1.34);
    needed = min(needed, k);

    for(int kk = 0; kk < needed; kk++){
        vector<int>B(n, 0);
        //int done = false;
        for(int i = 0; i < n; i++){
            int l = max(0, i - a[i]);
            int r = min(n - 1, i + a[i]);
            //cout << l << " " << r << endl; 
            B[l]++;
            if(r + 1 < n){
                B[r+1]--;
            }
        }
        for(int i = 1; i < n; i++){
            B[i] += B[i-1];
        }
        //int current_cnt = 0;
        //for(int i = 0; i < n; i++){
            //if(B[i] == n){
                //current_cnt += 1;
            //}
            //if(current_cnt == n){
                //done = true;
            //}
        //}
        a = B;
        //if(done){
            //break;
        //}else{
            //cnt += 1;
        //}
    }
    for(int i = 0; i < n; i++){
        cout << a[i] << " ";
    }cout << endl;
}



int main(){
    
    int n, k;
    cin >> n >> k;
    vector<int>a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    solve(n, k, a);
    //cout << solve(n, k, a) << endl;
    
}
