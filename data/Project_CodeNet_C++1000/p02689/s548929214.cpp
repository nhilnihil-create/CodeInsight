#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <string>
#include <map>
#include <iomanip>
#include <cmath>
#define rep(i,N) for(int i=0; i<N;i++)
using namespace std;

int main(){
    int N,M;
    cin>>N>>M;
    vector<long int> H(N);
    vector<int> A(M);
    vector<int> B(M);
    rep(i,N)cin>>H.at(i);
    rep(i,M)cin>>A.at(i)>>B.at(i);
    vector<int> T(N,1);
    rep(i,M){
        if(H.at(A.at(i)-1)>H.at(B.at(i)-1)){
            T.at(B.at(i)-1)=0;
        }else if(H.at(A.at(i)-1)==H.at(B.at(i)-1)){
            T.at(A.at(i)-1)=0;
            T.at(B.at(i)-1)=0;
        }else{
            T.at(A.at(i)-1)=0;
        }
    }
    int count=0;
    rep(j,N){
        int ok=1;
        if(T.at(j)==0){
            ok=0;
        }
        if(ok==1){
            count++;
        }
    }
    cout<<count<<endl;
    return 0;
}