#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>


using namespace std;

typedef long long ll;
typedef pair<ll,ll> P;

int main(){
    int N,K;
    cin >> N >> K;
    int R,S,P;
    cin >> R >> S >> P;
    string T;
    cin >> T;
    ll ans=0;
    for(int i=0; i<K; i++){
        char pre='o';
        for(int j=i; j<N; j+=K){
            if(T[j]=='s'){
                if(pre=='r'){
                    pre='o';
                    continue;
                }
                ans+=R;
                pre='r';
            }else if(T[j]=='p'){
                if(pre=='s'){
                    pre='o';
                    continue;
                }
                ans+=S;
                pre='s';
            }else{
                if(pre=='p'){
                    pre='o';
                    continue;
                }
                ans+=P;
                pre='p';
            }
        }
    }

    cout << ans << endl;


    return 0;
}