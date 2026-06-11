#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    // 整数の入力
    int N;
    int cnt=0;
    int a,b;
    cin >> N;
    for(int i=1;i<N;i++){
      for(int j=1;j*j<=N-i;j++){
         a = (N-i)%j;
         b = (N-i)/j;
        //cout << i <<" "<< j <<" " << (N-i)%j<< endl;
        if(a == 0){
          if(b == j){
            cnt+=1;
          }
          else{
            cnt+=2;
          }
       }
      }
    }

    cout << cnt << endl;
    return 0;
}
