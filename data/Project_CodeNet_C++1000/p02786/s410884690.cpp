#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define repit(it, li) for(auto it=li.begin(); it!=li.end(); it++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

ll ct(ll h){
   if(h==1) return 1;
   return 1+ct(h/2)*2;
}

int main(){
   ll h;
   cin>>h;

   cout<<ct(h)<<endl;
   return 0;
}
