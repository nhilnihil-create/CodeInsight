#include "bits/stdc++.h"
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll =long long;
using P =pair<int,int>;

int main(){
    int n,k;
    cin >> n >> k;
    int cc=0;
    vector <int> a(n+1,0),b(n+1,0),c(n+1,0),a2(n+1,0);
    rep(i,n){
        cin >> a[i];
    }
    rep(i,k){
        cc=0;
        b=c;
        a2=c;
        rep(j,n){
            if((j-a[j])<0){
                ++b[0];
            }
            else{
                ++b[j-a[j]];
            }
            if((j+a[j])>n-1){
                --b[n];
            }
            else{
                --b[j+a[j]+1];
            }
        }

        rep(j,n){
            //cout << b[i] << endl;
            if(j==0){
                a2[0]=b[0];
            }
            else{
                a2[j]=a2[j-1]+b[j];
            }
            if(a2[j]!=n){
                cc=1;
            }
        }


        a=a2;
        if(cc==0){
            break;
        }
    }

    rep(i,n){
        cout << a[i] << endl;
    }
    

    return 0;
}