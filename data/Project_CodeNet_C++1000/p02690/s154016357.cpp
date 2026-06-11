#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;


main(){
    ll x;cin>>x;
    for(int i = -120;i<=120;i++){
        for(int j=(-120);j<=120;j++){
            if((pow(i,5) - pow(j,5)) == x){
                cout<<i<<' '<<j;
                exit(0);
            }
        }
    }
}