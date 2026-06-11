#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main(){
    int N,c=0;
    cin>>N;
    for(int i=1;i<N;i++){
        for(int j=1;j<N;j++){
            if(N>i*j){
                c++;
            }else break;
        }
    }
    cout<<c<<"\n";
}