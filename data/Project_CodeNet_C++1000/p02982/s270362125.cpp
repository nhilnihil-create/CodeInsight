#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int N,D;
    cin >>N>>D;
    vector<vector<double>>vec(N,vector<double>(D));
    for(int i=0;i<N;i++){
        for(int j=0;j<D;j++){
            cin>>vec.at(i).at(j);
        }
    }
    int count=0;
    for(int i=0;i<N;i++){
        for(int j=i+1;j<N;j++){
            double AAA=0;
            for(int k=0;k<D;k++){
                double A=(vec.at(i).at(k)-vec.at(j).at(k))*(vec.at(i).at(k)-vec.at(j).at(k));
                AAA+=A;
            }
         for(int i=1;i<1000000;++i){
             if(i*i==AAA){
                 count ++;
                 break;
             }
         }
        }
    }
    cout <<count <<endl;
}