#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>   // popen, pclose, fgets
#include <cstdlib> 
using namespace std;
#define rep0(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
using ll = long long;
const double PI=3.14159265358979323846;
//小数点以下を指定したい時　　→→→→  cout << fixed << setprecision();

int main() {
    int n,k,d;cin>>n>>k;
    vector<int> p(n);
    rep0(i,k){
        cin>>d;
        vector<int> v(d);
        rep0(j,d){
            cin>>v[j];
            p[v[j]-1]=1;
        }
   }
   int count=0;
   rep0(i,n){
       if(p[i]==0){
           count++;
       }
   }
   cout<<count<<endl;
}