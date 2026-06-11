#include <iostream>
using namespace std;
int main(){
    long long n ;
    cin >> n;
    long long c=0;
    long long m;
    for (long long i = 1 ;  i <=n ;i++){
        cin >> m;
        if (i%2==1 && m%2==1){
            c++;
        }
    }
  cout<<c<<endl;
  return 0;
}
