#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <string>
#include <map>
#include <iomanip>
#define rep(i,N) for(int i=0; i<N;i++)
using namespace std;

int main(){
    int N,t;
    cin>>N;
    map<int,int> A;

    rep(i,N){
        cin>>t;
        A[t]=i+1;
    }
    for( auto i = A.begin(); i != A.end() ; ++i ) {
        if(i!=A.begin()) cout<<" ";
        cout << i->second;
    }
    cout<<endl;

    return 0;
}