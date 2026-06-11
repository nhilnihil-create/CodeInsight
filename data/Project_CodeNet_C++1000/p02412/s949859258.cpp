#include<iostream>
using namespace std;

int main(){
    int t = 0, n, x;
    while(1){
    cin >> n >> x;
    if(n == 0 && x == 0) break;
    ++n;
    for(int i = 1;i < n;++i){
      for(int j = 1;j < n;++j){
        for(int o = 1;o < n;++o){
         if(i + j + o == x){
         	if(i != j && i != o && j != o)
               t++;
              }
            }
          }
       }
        cout << t / 6 << endl;
        t = 0;
    } 
    return 0;
}