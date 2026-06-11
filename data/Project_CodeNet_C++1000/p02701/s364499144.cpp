#include<bits/stdc++.h>
#include<map>
using namespace std;
#define int long long

signed main(){
    // Your code here!
   int n;
   string tmp;
   
   map<string,int> mp{};
   
   cin >> n;
   for(int i = 0; i < n; i ++){
        cin >> tmp;
        mp[tmp] = 1;
   }
   cout <<  mp.size();
   
}
