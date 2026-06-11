#include <bits/stdc++.h>
using namespace std;


int main(){
    string S;
    cin>> S;
    if(S.size()%2==1){
        cout <<"No"<<endl;
        return 0;
    }
    for(long unsigned int i=0;i<S.size();i++){
        if(i%2==0&&S.at(i)=='h'){
            continue;
        }
        if(i%2==1&&S.at(i)=='i'){
            continue;
        }
        cout <<"No"<<endl;
        return 0;
    }
    cout <<"Yes"<<endl;
    return 0;
}
