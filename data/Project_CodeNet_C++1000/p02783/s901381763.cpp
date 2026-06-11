#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define repit(it, li) for(auto it=li.begin(); it!=li.end(); it++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
   int h, a;
   cin>>h>>a;

   int num=(h-1)/a+1;

   cout<<num<<endl;
   return 0;
}
