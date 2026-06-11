#include<bits/stdc++.h>
using namespace std;
int main(){
  int n; cin>>n;
    vector<int>arr(n);
    int left = 1, ans = 0;
    for (int i = 0; i < n; i++){
        cin>>arr[i];
    }
    for (size_t i = 0; i < n; i++)
    {
        if(arr[i] == left){
            left++;
        }
        else
        {
            ans++;
        }
    }
    if(left == 0 && ans == 1){
        cout << "-1" << endl;
    }
    else if(ans<n){
        cout << ans << endl;
    }
    else{
        cout << "-1" << endl;
    }
  return 0;
}