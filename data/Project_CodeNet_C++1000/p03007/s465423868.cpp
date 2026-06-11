#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<iostream>
#include<queue>
#include<vector>
#include <bitset>
#include<math.h>
#include<map>
#include<set>
#include <climits>
using namespace std;
#define INF 11000000000
#define MOD 1000000007
typedef long long ll;
typedef pair<int,int> P;

int main(){
    bool flagp=false,flagm=false,flag=false;
    int N,A[110000],temp=100000;
    ll tempm,tempp;
    ll ans=0;
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>A[i];
        if(A[i]<0) flagm=true;
        else if(A[i]==0) flagp=true;
        else flagp=true;
        
        ans+=abs(A[i]);
        temp=min(temp,abs(A[i]));
    }
    if(!flagp) sort(A,A+N,greater<int>());
    else sort(A,A+N);
    if(flagm && flagp){
        cout<<ans<<endl;
        tempm=A[N-1]; tempp=A[0];
        for(int i=1;i<N-1;i++){
            if(A[i]<=0){
                cout<<tempm<<" "<<A[i]<<endl;
                tempm-=A[i];
            }else{
                cout<<tempp<<" "<<A[i]<<endl;
                tempp-=A[i];
            }
        }
        cout<<tempm<<" "<<tempp<<endl;
    }else{
        ans-=temp*2;
        cout<<ans<<endl;
        temp=A[0];
        for(int i=1;i<N-1;i++){
            cout<<temp<<" "<<A[i]<<endl;
            temp-=A[i];
        }
        if(flagp) cout<<A[N-1]<<" "<<temp<<endl;
        else cout<<temp<<" "<<A[N-1]<<endl;
    }
}
