#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>

using namespace std;

#define REP(i, x) for(int i=0;i<(int)(x);i++)
#define REPS(i, x) for(int i=1;i<=(int)(x);i++)
#define RREP(i, x) for(int i=(int)(x)-1;i>=0;i--)
#define RREPS(i, x) for(int i=(int)(x);i>0;i--)
#define FOR(i, x) for(auto it=x.begin();it!=x.end();++it)
typedef long long ll;
typedef vector<int> vi;

int n, p[300000];

int c(int x){
        return p[max(x-1, 0)];
}

int main(){
        for(int i=2;i<300000;i++){
                if(!p[i]){
                        for(ll j=(ll)i*i;j<300000;j+=i) p[j]=1;
                }
                p[i] = !p[i];
        }
        REP(i, 300000) p[i+1] += p[i];
        while(cin >> n, n){
                cout << c(2*n+1) - c(n+1) << endl;
        }
        return 0;
}