#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
    int N;
    cin>>N;

    vector<int> s(N,0);
    int a;
    for(int i=0;i<N-1;i++){
        cin>>a;
        s[a-1]++;
    }

    for(auto p:s){
        cout<<p<<endl;
    }

    return 0;
}