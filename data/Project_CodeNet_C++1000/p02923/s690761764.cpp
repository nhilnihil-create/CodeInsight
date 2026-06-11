#include <bits/stdc++.h>
using namespace std;
int main(){
   int n;
   int cnt = 0;
   cin >> n;
   vector<int> v(n);
   vector<int> v2;
   for(int i=0;i<n;i++)cin >> v[i];
   for(int i=0;i<n-1;i++){
       if(v[i] >= v[i+1])cnt++;
       else{
           v2.push_back(cnt);
           cnt = 0;
       }
   }
   v2.push_back(cnt);
   sort(v2.begin(),v2.end());
   cout << v2[v2.size()-1] << endl;
}