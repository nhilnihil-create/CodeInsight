#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int X;
    cin >>X;
    for(int i=0;i<=1000;i++){
        if(i*100<=X&&X<=i*105){
            cout <<1<<endl;
            return 0;
        }
    }
  cout <<0<<endl;
}