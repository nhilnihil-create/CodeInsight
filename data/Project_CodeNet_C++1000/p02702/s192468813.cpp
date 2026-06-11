#include <bits/stdc++.h>
using namespace std;

int mod_count[2019]={};

int main(){
    string S;
    cin >> S;

    int N = (int) S.size();
    int Smod[N],Tenpow[N];

    for(int i=N-1; i>=0; i--){
        if(i==N-1){
            Smod[i] = (int) ( S[i] - '0' );
            Tenpow[i] = 1;
            mod_count[Smod[i]]++;
        }else{
            Tenpow[i] = Tenpow[i+1]*10 % 2019;
            Smod[i] = (Smod[i+1] + ( (int) ( S[i] - '0' ) )*Tenpow[i])%2019;
            mod_count[Smod[i]]++;
        }
    }
    mod_count[0]++;

    long ans=0;

    for(int i=0; i<2019; i++){
        //if(mod_count[i]!=0) cout << "i mod_count " << i << " " << mod_count[i] << endl;
        ans += ( (long) mod_count[i] )*( (long) mod_count[i] - 1l )/( 2l );
    }

    cout << ans << endl;

    return 0;
}