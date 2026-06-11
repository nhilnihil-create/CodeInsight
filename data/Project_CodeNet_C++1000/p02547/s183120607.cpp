#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main(){
    int N,D[2],c=0;
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>D[0]>>D[1];
        if(D[0]==D[1])c++;
        else c=0;
        if(c>=3){
            cout<<"Yes\n";
            break;
        }
        else if(i==N-1)cout<<"No\n";
    }
}