#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
  ll A,V,B,W,T;
  cin>>A>>V>>B>>W>>T;
  ll D=abs(A-B);
  ll D2=(V-W)*T;
  puts(D<=D2?"YES":"NO");
}