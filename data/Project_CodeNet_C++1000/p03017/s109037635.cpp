#include<iostream>
#include<math.h>
#include<vector>
#include<array>
#include<algorithm>
#include<numeric>
#include<map>
#include<queue>
#include<deque>
#include<set>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vector<ll>> mat;

int main(){
    int N,A,B,C,D;cin>>N>>A>>B>>C>>D;
    string S;cin>>S;
    if(C<D){
        int i=A;
        while(i<D-1){
            if(S[i]=='#' && S[i+1]=='#'){
                cout<<"No"<<endl;
                return 0;
            }
            i++;
        }
        cout<<"Yes"<<endl;
        return 0;
    }
    else{
        int i=A;
        while(i<C-1){
            if(S[i]=='#' && S[i+1]=='#'){
                cout<<"No"<<endl;
                return 0;
            }
            i++;            
        }
        int j=B-2;
        while(j<D-1){
            if(S[j]=='.' && S[j+1]=='.' && S[j+2]=='.'){
                cout<<"Yes"<<endl;
                return 0;
            }
            j++;
        }
        cout<<"No"<<endl;
        return 0;
    }
    return 0;
}