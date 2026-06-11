#include <bits/stdc++.h>
using namespace std;
 
int main() {
  vector<int>A(9);
  vector<bool>C(9,false);
  for(int X=0;X<9;X++){
    cin>>A[X];
  }
  int N;
  cin>>N;
  vector<int>B(N);
  for(int X=0;X<N;X++){
    cin>>B[X];
    for(int Y=0;Y<9;Y++){
      if(B[X]==A[Y]){
        C[Y]=true;
      }
    }
  }
  if(C[0]==true&&C[3]==true&&C[6]==true){
    cout<<"Yes"<<endl;
  }
  else if(C[1]==true&&C[4]==true&&C[7]==true){
    cout<<"Yes"<<endl;
  }
  else if(C[2]==true&&C[5]==true&&C[8]==true){
    cout<<"Yes"<<endl;
  }
  else if(C[0]==true&&C[1]==true&&C[2]==true){
    cout<<"Yes"<<endl;
  }
  else if(C[3]==true&&C[4]==true&&C[5]==true){
    cout<<"Yes"<<endl;
  }
  else if(C[6]==true&&C[7]==true&&C[8]==true){
    cout<<"Yes"<<endl;
  }
  else if(C[0]==true&&C[4]==true&&C[8]==true){
    cout<<"Yes"<<endl;
  }
  else if(C[2]==true&&C[4]==true&&C[6]==true){
    cout<<"Yes"<<endl;
  }
  else{
    cout<<"No"<<endl;
  }
}
