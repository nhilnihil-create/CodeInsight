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
    long int N;
    long int ans=1;
    string S;
    cin >>N;
    cin >>S;
    char interm=S[0];
    for(int i=1;i<S.size();i++){
        if(S[i]==interm){
            continue;
        }else{
            ans++;
        }
        interm=S[i];
    }
    cout <<ans<<endl;
    return 0;
}