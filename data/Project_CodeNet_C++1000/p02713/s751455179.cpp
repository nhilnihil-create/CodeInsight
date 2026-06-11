#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define rep3(i,n) for (long long i=0; i<(long long)(n); i++)
using Graph = vector<vector<int>>;
using ll = long long;


int main() {
    int k;
    cin>>k;
    ll sum=0;
    rep(i,k){
        int a=i+1;
        rep(j,k){
            int b=j+1;
            rep(l,k){
                int c=l+1;
                int p=min(a,min(b,c));
                while(p>0){
                    if(a%p==0){
                        if(b%p==0){
                            if(c%p==0){
                                sum+=p;
                                break;
                            }
                        }
                    }
                    p--;
                }
            }
        }
    }
    cout<<sum<<endl;
}