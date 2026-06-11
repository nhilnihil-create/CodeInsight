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
    map<int,int> maps;
    for(int i = 0;i < (int)n; i++){
        maps[arr[i]] = i+1;    
    }       
    for(auto itr : maps){
      cout << itr.second << " ";
    }
    return 0;
}
