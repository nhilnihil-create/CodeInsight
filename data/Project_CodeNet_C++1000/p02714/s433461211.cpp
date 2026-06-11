#include <stdio.h>
#include <math.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
typedef long long ll;
 
int main(void)
{
    string str;
    int N;
    cin >> N;
    cin >> str;
    ll R,G,B;
    R=B=G=0;
    for(int a=0;a<N;a++){
        if(str[a]=='R'){
            R++;
        }else if(str[a]=='G'){
            G++;
        }else{
            B++;
        }
    }
    ll ans=R*G*B;
    for(int a=1;a<=N;a++){
        for(int x=0;x+2*a<N;x++){
            char k=str[x];
            char f=str[x+a];
            char g=str[x+2*a];
            if(k!=f&&f!=g&&g!=k){
                ans--;
            }
        }
    }
    cout << ans <<endl;
}