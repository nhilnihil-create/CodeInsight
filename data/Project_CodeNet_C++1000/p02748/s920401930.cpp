#include <bits/stdc++.h>
using namespace std;

int main(){
  int a,b,m;
  cin>>a>>b>>m;
vector<int> renzi(a);
vector<int> ref(b);

vector<int> total(m);
int saisyo=300000;
  for(int i=0;i<a;i++){
   cin>>renzi[i]; 
  }
  for(int i=0;i<b;i++){
   cin>>ref[i]; 
  }

  for(int j=0;j<m;j++){
   int x,y,c;
    cin>>x>>y>>c;
    total[j]=renzi[x-1]+ref[y-1]-c;
    if(saisyo>total[j])saisyo=total[j];
  }
    sort(renzi.begin(),renzi.end());
  sort(ref.begin(),ref.end());
       if(renzi[0]+ref[0]<saisyo)saisyo=renzi[0]+ref[0];
      cout<<saisyo<<endl;
  
}