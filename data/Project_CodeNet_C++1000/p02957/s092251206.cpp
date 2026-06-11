#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int a,b;
    cin>>a>>b;
    bool t = true;
    if((a>b) || (a==b)){
        for(int i=0;i<a;i++){
            if(abs(a-i) == abs(b-i)){
                cout<<i<<endl;
                t = false;
            }
        }
    }
    else{
        if((a<b) || (a==b)){
        for(int i=0;i<b;i++){
            if(abs(b-i) == abs(a-i)){
                cout<<i<<endl;
                t = false;
            }
        }
    }
}
    if(t){
            cout<<"IMPOSSIBLE"<<endl;

    }

}
