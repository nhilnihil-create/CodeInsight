#include <bits/stdc++.h>
#include<iostream>
#include <string>
using namespace std;
 
int main() {
    int A,B,M;

    cin >> A >> B >> M;
    vector<int>a(A);
    vector<int>b(B);

    for(int i = 0;i < A;i++){
        cin >> a.at(i);
    }
    for(int i = 0;i < B;i++){
        cin >> b.at(i);
    }
    

    int tmp,x,y,z,ans(9999999);
      for(int i = 0;i < M;i++){
        
            cin >> x >> y >> z;
          	x--;
          	y--;
          	tmp = a[x] + b[y] - z;
          	ans = min(ans,tmp);
          
    }
   
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    tmp = a.at(0) + b.at(0);
    ans = min(ans,tmp);
    cout << ans;
    
}