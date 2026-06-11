#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int M,D;
    cin>>M>>D;
    int count = 0;
    for(int i = 1;i<= M;i++){
        for(int j = 1;j<= D;j++){
            int d1,d10;
            d1 = j%10;
            d10 = j/10;
            if(i==d1*d10 && d1>=2 && d10>=2){
                count++;
            }
        }
    }
    cout<<count<<endl;
}


