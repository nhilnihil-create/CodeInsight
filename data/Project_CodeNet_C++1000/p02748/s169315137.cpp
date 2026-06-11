#include<iostream>
#include<vector>
using namespace std;

int main(){
   int a,b,m;
   cin >> a >> b >> m;
   vector<int> A(a,0);
   vector<int> B(b,0);
   int a_min = 1000000;
   int b_min = 1000000;
   for(int i=0;i<a;i++){
       cin >> A[i];
       if(a_min>A[i]) a_min = A[i];
   }
   for(int i=0;i<b;i++){
       cin >> B[i];
       if(b_min>B[i]) b_min = B[i];
   }
   int c_min = 1000000;
   for(int i=0;i<m;i++){
       int x,y,c;
       cin >> x >> y >> c;
       x--;
       y--;
       if(c_min>A[x]+B[y]-c) c_min = A[x]+B[y]-c;
   }
   cout << min(c_min,a_min+b_min) << endl;
}