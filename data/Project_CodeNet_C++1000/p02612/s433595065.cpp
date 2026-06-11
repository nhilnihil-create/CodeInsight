#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int N;
    cin>>N;
    N = N%1000;
    if(N==0){
        cout<<0<<endl;
    }
    else{
        N=1000-N;
        cout<<N<<endl;
    }
}