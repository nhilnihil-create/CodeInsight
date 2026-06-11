#include <iostream>
#include <numeric>

using namespace std;

#define rep(i,n) for(int i=0;i<(n);++i)

typedef long long ll;

int main(){

    char S[4];
    char T[4];

    scanf("%s",S);
    scanf("%s",T);

    int count=0;

    rep(i,3){
        if(S[i]==T[i]){
            ++count;
        }
    }

cout<<count<<endl;


}
