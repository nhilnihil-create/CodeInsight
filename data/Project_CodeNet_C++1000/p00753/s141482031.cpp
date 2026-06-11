#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0;i<(n);i++)
#define REAP(i,a,n) for(int i=(a);i<(n);i++)
#define YES cout<<"Yes"<<endl
#define NO cout<<"No"<<endl
#define fr first
#define sc second
#define pb push_back
#define All(v) v.begin(),v.end()
typedef long long ll;

#define N 10000000

int prinum[N];

void prime(){
    for(int i=2;i*i<N;i++){
        if(prinum[i]==1)continue;
        for(int j=i*2;j<N;j+=i){
            prinum[j]=1;
        }
    }
}

int main(){
    int n,cou;
    prinum[0]=prinum[1]=1;
    prime();
    while(cin >> n,n){
        cou=0;
        for(int i=n+1;i<=2*n;i++){
            if(prinum[i]==0)cou++;
        }
        cout << cou << endl;
    }
}

