#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(void){
   
   int n, k;
   cin >> n >> k;
   
   vector<int> a(n);
   for (int i = 0; i < n; i++) cin >> a[i];
   
   for (int i = 0; i < k; i++){
       
       vector<int> cumulativeSum(n+1);
       
       for (int j = 0; j < n; j++){
           int l = max(0,j-a[j]);
           int r = min(n,j+a[j] + 1);
           
           cumulativeSum[l]++;
           cumulativeSum[r]--;
        }
        
        for (int j = 0; j < n; j++) cumulativeSum[j+1] += cumulativeSum[j];
        
        cumulativeSum.pop_back();
        if (a == cumulativeSum) break;
        a = cumulativeSum;
   } 
   
   
   for (int p: a) cout << p << endl;
}
