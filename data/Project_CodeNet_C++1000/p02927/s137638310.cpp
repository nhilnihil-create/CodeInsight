#include<iostream>

using namespace std;

int main(){
    int m,d,temp=0;
    cin>>m>>d;

    for(int i=1;i<=m;i++){
        for(int j = 21;j<=d;j++){
            int ones = j%10;
            int tens = j/10;
            int multi = ones*tens;
            if(multi == i && tens>=2 && ones>=2){
                temp++;
            }
        }
    }
    cout<<temp<<endl;

}
