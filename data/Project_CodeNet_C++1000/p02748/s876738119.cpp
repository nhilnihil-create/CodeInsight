#include <bits/stdc++.h>
#include <math.h>
using namespace std;
int main(){
    int A,B,M;
    cin>>A>>B>>M;
    vector<int>a(A);
    vector<int>b(B);
    vector<vector<int>>m(M,vector<int>(3));
    for(int i=0;i<A;i++){cin>>a.at(i);}
    for(int i=0;i<B;i++){cin>>b.at(i);}
    for(int i=0; i<M;i++){
      cin>>m.at(i).at(0)>>m.at(i).at(1)>>m.at(i).at(2);
    }
    int minA=*min_element(a.begin(),a.end());
    int minB=*min_element(b.begin(),b.end());
    int ans=minA+minB;

    for(int i=0; i<M;i++){
      int p=a.at(m.at(i).at(0)-1)+b.at(m.at(i).at(1)-1)-m.at(i).at(2);
      ans=min(ans,p);
    }
    
    cout<<ans<<endl;
    return 0;
}