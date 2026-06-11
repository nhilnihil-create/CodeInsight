#include<iostream>
using namespace std;

int main() {
    int N;
    cin>>N;
    long tmp;
    long ans=0;
    for(int i=0;i<N;++i){
        cin>>tmp;
        ans ^= tmp;
    }
    if(!ans)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}
