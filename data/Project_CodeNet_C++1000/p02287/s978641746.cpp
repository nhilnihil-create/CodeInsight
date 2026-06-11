#include<iostream>
using namespace std;
#define MAX 250

int parent(int i){
    return i/2;
}

int left(int i){
    return i*2;
}

int right(int i){
    return i*2+1;
}

int main(){
    int H,h[MAX+1];
    cin>>H;
    for(int i=1;i<=H;i++) cin>>h[i];

    for(int i=1;i<=H;i++){
        cout<<"node "<<i<<": ";
        cout<<"key = "<<h[i]<<", ";
        if(parent(i)>=1) cout<<"parent key = "<<h[parent(i)]<<", ";
        if(left(i)<=H) cout<<"left key = "<<h[left(i)]<<", ";
        if(right(i)<=H) cout<<"right key = "<<h[right(i)]<<", ";
        cout<<endl;
    }
}
