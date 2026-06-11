#include<bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> p(n);
    rep(i,n) cin >> p[i];

    int MIN = 100;
    int res=0;
    for(int i=0; i<n; i++){
        if(i == 0){
            MIN = p[i];
            res++;
        }else{
            if(MIN >= p[i]){
                MIN = p[i];
                res++;
            }
        }
    }

    cout << res << endl;
    return 0;
}
