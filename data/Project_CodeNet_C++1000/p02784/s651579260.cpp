#include <iostream>
#include <string>
#include <vector>
using ll=long long;
using namespace std;

int main(){
    int H,N;
    int a;
    int sum=0;
    cin>>H>>N;
    for(int i=0;i<N;i++){
        cin>>a;
        sum+=a;
    }

    if(H<=sum){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }

    return 0;
}