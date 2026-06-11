#include<bits/stdc++.h>
using namespace std;

int main(){
    int a,b;
    cin>>a>>b;
    
    for(int i = 1; i < 2000; i++){
        int aa = i*8/100; int bb = i*10/100;
        if(aa==a && bb == b){
          cout<<i;
          return 0;
        }
    }
    cout<<-1;

}
