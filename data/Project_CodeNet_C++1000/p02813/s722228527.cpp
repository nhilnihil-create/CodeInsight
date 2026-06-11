#include<bits/stdc++.h>
using namespace std;
int main(){
    int n; cin >> n;
    int a,b;
    bool B = true;
    bool B2 = true;
    int cnt = 0;
    vector<int> x(n); vector<int> y(n);
    for(int i=0;i<n;i++)cin >> x[i];
    for(int i=0;i<n;i++)cin >> y[i];
    vector<int> v(n);
    for(int i=0;i<n;i++)v[i] = i+1;
   do{
       cnt++;
       for(int i=0;i<n;i++){
           if(!(v[i] == x[i]))B = false;
           if(!(v[i] == y[i]))B2 = false;
       }
       if(B)a = cnt;
       if(B2)b = cnt;
       B = true;
       B2 = true;
   }while(next_permutation(v.begin(),v.end()));
   cout << abs(a-b) << endl;
}