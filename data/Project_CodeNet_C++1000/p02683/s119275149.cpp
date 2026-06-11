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
    int N,M,X;
    cin>>N>>M>>X;
    vector<vector<int> > A(N, vector<int>(M));
    vector<int> C(N);
    rep(i,N){
        cin>>C.at(i);
        rep(j,M){
            cin >>A.at(i).at(j);
        }
    }
    vector<int> comb(N);
    int min_c=pow(10,7);
    rep(k,pow(2,N)-1){
        comb.at(0)++;
        rep(i,N){
            if(comb.at(i)>1){
                comb.at(i+1)++;
                comb.at(i)=0;
            }
           // cout<<comb.at(i)<<" ";
        }
        vector<int> calc(M);
        int ok=1;
        int cost=0;
        rep(i,N){
            rep(j,M){
                calc.at(j)+=A.at(i).at(j)*comb.at(i);
            }
            cost+=C.at(i)*comb.at(i);
        }
        rep(i,M){
            if(calc.at(i)<X){
                ok=0;
            }
        }
        if(ok==1){
            if(cost<min_c){
                min_c=cost;
            }
        }


       // cout<<endl;
    }
    if(min_c==pow(10,7))min_c=-1;
    cout<<min_c<<endl;




    return 0;
}