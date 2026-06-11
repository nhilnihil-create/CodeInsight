#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
#define MAXN 500005

//<>>><<><<<<<>>><
string S;
int N;
int Left[MAXN], Right[MAXN];
ll ans;

int main(void){
    //cout<<"AGC 040 a\n";
    cin>>S;
    N=S.length()+1;
    
    for(int i=0; i<N-1; i++){
        if(S[i]=='<'){
            Left[i+1]=Left[i]+1;
        }else{
            Left[i+1]=0;
        }
    }
    
    for(int i=N-2; i>=0; i--){
        if(S[i]=='>'){
            Right[i]=Right[i+1]+1;
        }else{
            Right[i]=0;
        }
    }
    
    for(int i=0; i<N; i++){
        ans += max(Left[i], Right[i]);
    }
    cout<<ans;
    
    return 0;
}
