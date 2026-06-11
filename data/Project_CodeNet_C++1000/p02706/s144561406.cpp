#include<bits/stdc++.h>
using namespace std;
int main()
{
   int n,m;
   cin >> n >> m;
   int x=0,arr[100000];
   for(int i=0;i<m;i++) {
       //int arr[10000];
       cin >> arr[i];
   }
   for(int i=0;i<m;i++) {
       x += arr[i];
   }
   if(x>n)
      cout << "-1" << endl;
   else
      cout << n-x << endl;
}
