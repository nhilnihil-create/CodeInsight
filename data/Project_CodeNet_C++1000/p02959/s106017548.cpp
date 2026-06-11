#include <bits/stdc++.h>
using namespace std;
 
int main() {
    long long N;
    cin >>N;
    vector<long long>vecA(N+1);
    vector<long long>vecB(N);
    for(int i=0;i<N+1;i++){
        cin >>vecA.at(i);
    }
    for(int i=0;i<N;i++){
        cin >>vecB.at(i);
    }
   long long summ=0;
    for(int i=0;i<N;i++){
    long long stand3=vecA.at(i)-vecB.at(i);
    long long stand4=vecB.at(i)-vecA.at(i);
    if(stand3>=0){
        summ+=vecB.at(i);
    }
    else{
        summ+=vecA.at(i);
        if(vecA.at(i+1)>=stand4){
            summ+=stand4;
            vecA.at(i+1)-=stand4;
        }
        else{
            summ+=vecA.at(i+1);
            vecA.at(i+1)=0;
        }
     }
    }
    cout <<summ<<endl;
}