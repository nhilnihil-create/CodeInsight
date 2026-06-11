#include <iostream>
using namespace std;
int Func(int m){
     return m*(m-1)/2;
}
int main(){
     int N,M;
     cin>>N>>M;
     cout <<Func(N)+Func(M)<<endl;
}
