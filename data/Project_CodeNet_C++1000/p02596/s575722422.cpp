#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main(void){
    int k,num=0;
    cin>>k;
    for (int i = 0; i < 10e6; i++)
    {
        num=(10*num+7)%k;
        if (num==0){
            cout<<1+i<<endl;
            return 0;}
        
    }
    cout<<-1<<endl;
    return 0;
}