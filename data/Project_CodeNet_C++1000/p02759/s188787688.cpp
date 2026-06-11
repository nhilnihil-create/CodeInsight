#include <iostream>
using namespace std;
int floor(int A){
     if(A%2==0)return A/2;
     if(A%2!=0)return A/2+1;
}
int main(){
     int N;
     cin >>N;
     cout <<floor(N)<<endl;

}
