#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(void){
   int n;
   cin >> n;
   vector<pair<int,int>> p(n);
   
   for(int i = 0;i < n;i++){
         int x,l;
         cin >> x >> l;
         p[i].first = x + l;
         p[i].second = x - l;
         
   }
   sort(p.begin(),p.end());
   int ans = 1;
   int t = p[0].first;
   for(int i = 1;i < n;i++){
         if(t <= p[i].second){
               ans++;
               t = p[i].first;
         }
   }
   cout << ans << endl;
}
