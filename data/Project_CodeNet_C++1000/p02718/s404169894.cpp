#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(void){
   int n,m;
   cin >> n >> m;
   vector<int> a(n);
   int s = 0;
   for(int i = 0;i < n;i++){
         cin >> a[i];
         s += a[i];
   }
   
   sort(a.begin(),a.end(),greater<int>());
   int t = 0;
   for(int i = 0;i < m;i++){
         if(a[i] * 4 * m < s){
               cout << "No" << endl;
               return 0;
         }
   }
   cout << "Yes" << endl;
   return 0;
   
}
