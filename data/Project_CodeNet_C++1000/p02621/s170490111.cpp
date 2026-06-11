#include <iostream>
using namespace std;

int power(int p,int n){
     int back=p;
    for(int i=0;i<n-1;i++){
         back *=p;
    }
    return back;
}
int main(){
     int A;
     cin >>A;
     cout << A+power(A,2)+power(A,3)<<endl;
}
