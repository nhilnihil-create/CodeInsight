#include<iostream>
using namespace std;
 
int main(){
    int N,M;
    int A, B;
    cin>>N>>M;
    int ans = N;
    int mountains[100001] = {};
    int list[100001]={};
    for(int i =1;i < N+1; i++){
        cin >>mountains[i];
    }
    for(int i =0; i< M; i++){
        cin >>A>>B;
        if(mountains[A]>mountains[B]){
            if(list[B]==0) ans = ans-1;
            list[B]=1;
        }else if(mountains[A]<mountains[B]){
            if(list[A]==0) ans = ans-1;
            list[A] = 1;
        } else{
            if(list[A]==0) ans = ans-1;
            if(list[B]==0) ans = ans-1;
            list[A]= 1;
            list[B] = 1;
        }
        //cout<<A<<" "<<B<<"list"<<list[A]<<" "<<list[B]<<endl;
        //cout <<"ans"<<ans<<endl;
    }
    cout <<ans<<endl;
    return 0;
}