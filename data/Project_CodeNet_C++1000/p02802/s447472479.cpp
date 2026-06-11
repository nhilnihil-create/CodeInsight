
#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int N,M;
    cin >>N>>M;
    vector<int>vec(N,0);
    vector<int>vec2(N,0);
    for(int i=0;i<M;i++){
        int x;
        string y;
        cin >>x>>y;
        if(vec.at(x-1)==0){
        if(y=="AC"){
            vec.at(x-1)++;
        }
        if(y=="WA"){
            vec2.at(x-1)++;
        }
      }
    }
    int WAcount=0;
      int ACcount=0;
      for(int i=0;i<N;i++){
          if(vec.at(i)==1){
              ACcount++;
              WAcount+=vec2.at(i);
          }
      }
      cout <<ACcount<<" "<<WAcount<<endl;;
}