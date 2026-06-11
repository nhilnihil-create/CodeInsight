#include <bits/stdc++.h> 
#define rep(i, n) for(long long i = 0; i < (long long)(n); i++)
#define all(x) (x).begin(),(x).end()
#define _GLIBCXX_DEBUG
typedef long long ll;
using namespace std;
int main(){
  int m,d;
  cin>>m>>d;
  if(d<22||m<4){cout<<0<<endl;}
  else{int k=0;
       for(int j=4;j<=m;j++){
         for(int i=22;i<=d;i++){
           if(i/10>=2&&i%10>=2&&(i/10)*(i%10)==j){k++;}
         }}
        cout<<k<<endl;}
}