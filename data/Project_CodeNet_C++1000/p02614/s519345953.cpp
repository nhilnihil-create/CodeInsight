#include <bits/stdc++.h>
using namespace std;

int main() {
int64_t a,b,c,ans,cou;
cin>>a>>b>>c;
  cou=0;
vector<vector<char>> data(a, vector<char>(b));
for(int64_t i=0;i<a;i++){
  for(int64_t j=0;j<b;j++){
    cin>>data.at(i).at(j);
  }
}  
for(int64_t i=0;i<pow(2,a);i++){
  for(int64_t j=0;j<pow(2,b);j++){
    int64_t p,q;
    p=i;
    q=j;
    ans=0;
    vector<int64_t> va(a);
    vector<int64_t> vb(b); 
    for(int64_t k=0;k<a;k++){
      if(p%2==1){va.at(k)=1;}
      p=p/2;
    }
    for(int64_t k=0;k<b;k++){
      if(q%2==1){vb.at(k)=1;}
      q=q/2;
    }
    for(int64_t k=0;k<a;k++){
      for(int64_t l=0;l<b;l++){
       if(data.at(k).at(l)=='#'&&va.at(k)==0&&vb.at(l)==0){ans++;}
      }
    }
    if(ans==c){cou++;}
  }
} 
cout<<cou<<endl;
} 