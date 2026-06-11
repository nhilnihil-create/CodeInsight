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

#define N 1000001

bool pri[N];

void pn(){
    pri[0]=pri[1]=true;
    for(int i=2;i*i<N;i++){
        if(pri[i])continue;
        for(int j=2*i;j<N;j+=i){
            pri[j]=true;
        }
    }
}

int main(){
    int a,d,n,cou;
    pn();
    while(cin >> a >> d >> n,n){
        cou=0;
        for(int i=a;;i+=d){
            if(!pri[i]){
                cou++;
            }
            if(cou==n){
                cout << i << endl;
                break;
            }
        }
    }

}

