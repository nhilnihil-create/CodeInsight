#include <iostream>
#include<queue>
using namespace std;
struct ST{
    char name[11];
    int tim;
};
int main(void){
    queue<ST> Q;
    ST syori;
    int n,q;
    cin>>n>>q;
    for(int i=0;i<n;i++){
        cin>>syori.name>>syori.tim;
        Q.push(syori);
    }
    int sum=0;
    while(!Q.empty()){
        syori=Q.front();
        Q.pop();
        if(syori.tim<=q){
            cout<<syori.name<<" "<<syori.tim+sum<<endl;
            sum+=syori.tim;
        }
        else{
            sum+=q;
            syori.tim-=q;
            Q.push(syori);
        }
    }
}

