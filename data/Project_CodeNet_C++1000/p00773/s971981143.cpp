#include<iostream>

using namespace std;

int main(){

    while(1){
        int x, y, s;
        cin>> x>> y>> s;
        if(!(x||y||s)) break;
        int ma=0;
        for(int i=1; i<s; i++){
            for(int j=1; j<s; j++){
                int mae1=i*(100+x)/100;
                int mae2=j*(100+x)/100;
                if(mae1+mae2==s){
                    ma=max(ma, i*(100+y)/100+j*(100+y)/100);
                }
            }
        }

        cout<< ma<< endl;
    }

    return 0;
}