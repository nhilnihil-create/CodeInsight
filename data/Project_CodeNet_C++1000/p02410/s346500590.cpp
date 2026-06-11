#include <iostream>
using namespace std;
int main(void){
    // Your code here!
    int a,b,x;
    cin>>a>>b;
    int ac[a][b] ,bc[b];
    for(int i = 0;i<a;i++){
        for(int u = 0;u<b;u++){
            cin>>ac[i][u];
        }
    }
  
    
    for(int k = 0;k<b;k++){
        cin>>bc[k];
    }
    for(int i = 0;i<a;i++){
        for(int u = 0;u<b;u++){
            x += ac[i][u]*bc[u];
        }
        cout<<x<<endl;
        x = 0;
    }
}

