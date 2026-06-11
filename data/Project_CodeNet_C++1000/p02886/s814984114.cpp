#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ar array



int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0;i < (int)n; i++){
      cin >> arr[i];
    }
    ll sum = 0;
    for(int i = 0;i < (int)n; i++){
     for(int j = i+1;j < (int)n; j++){
          sum += arr[i]*arr[j];
     }    
    }    
    cout << sum;
    
    return 0;
}
