#include <bits/stdc++.h>
#include <math.h>
using namespace std;
int main(){
    int A,B,M;
    cin>>A>>B>>M;
    vector<int>a(A);
    vector<int>b(B);
    vector<vector<int>>m(M+100,vector<int>(100));
    for(int i=0;i<A;i++){cin>>a.at(i);}
    for(int i=0;i<B;i++){cin>>b.at(i);}
    for(int i=0; i<M;i++){
      cin>>m.at(i).at(0)>>m.at(i).at(1)>>m.at(i).at(2);
    }
    int cos=a.at(m.at(0).at(0)-1)+b.at(m.at(0).at(1)-1)-m.at(0).at(2);
    for(int i=0; i<M;i++){
      int p=a.at(m.at(i).at(0)-1)+b.at(m.at(i).at(1)-1)-m.at(i).at(2);
      if(cos>=p){cos=p;}
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    if(a.at(0)+b.at(0)<cos){cout<<a.at(0)+b.at(0)<<endl;}
    else{cout<<cos<<endl;}
    return 0;
}