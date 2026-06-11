#include <bits/stdc++.h>

using namespace std;

int main(){
    int ans = 0;
    int ans1 = 0;
    int n, a, b;
 
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> a >> b;
        if(a == b){
            ans++;
        }else{

            if(ans > ans1){
                ans1 = ans;
                ans = 0;
            }else{
                ans = 0;
            }
        }
    }
   if(ans > ans1){
      ans1 = ans;
    }
  if(ans1 >= 3){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }

}