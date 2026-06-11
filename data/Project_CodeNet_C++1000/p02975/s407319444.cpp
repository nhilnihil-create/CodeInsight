#include <iostream>
#include <map>
#include <set>
using namespace std;

int main(){
  int N,a,c;
  map<int,int> A{};
  set<int> judge;
  cin >> N;
  for(int i=0;i<N;i++){
    cin >> a;
    A[a]++;
  }
    switch( A.size() ){
      case 1:
        if( A.find(0)!=A.end() ){
          cout << "Yes" << endl;
        }else{
          cout << "No" << endl;
        }
        break;
      case 2:
        if( A.find(0)==A.end() || N!=A[0]*3 ){
          cout << "No" << endl;
        }else{
          cout << "Yes" << endl;
        }
        break;
      case 3:
        {
        int x,y,z;
        int Nx,Ny,Nz;
        auto itr=A.begin();
        x=itr->first;
        Nx=itr->second;

        itr=next(itr);
        y=itr->first;
        Ny=itr->second;

        itr=next(itr);
        Nz=itr->second;
        z=itr->first;
        if( 3*Nx==N && 3*Ny==N && 3*Nz==N ){
          while(z>0){
            judge.insert(z%2*4+y%2*2+x%2);
            x/=2;
            y/=2;
            z/=2;
          }
          if(judge.find(1)==judge.end() && 
             judge.find(2)==judge.end() && 
             judge.find(4)==judge.end() && 
             judge.find(7)==judge.end()
            ){
            cout << "Yes" << endl;
          }else{
            cout << "No" << endl;
          }
        }else{
          cout << "No" << endl;
        }
        }
        break;
      default:
        cout << "No" << endl;
        break;
    }
  
}