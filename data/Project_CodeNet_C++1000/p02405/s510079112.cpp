#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main(){

    ll h, w;

    while (scanf("%lld%lld",&h,&w)&&h&&w){

        char c = '#';

        for (ll i=1; i<=h; i++){
            if (i%2==1){
                for (ll j=1; j<=w; j++){
                    if (j%2==1)
                        cout << '#';
                    else
                        cout << '.';
                }
            }
            else{
                for (ll j=1; j<=w; j++){
                    if (j%2==1)
                        cout << '.';
                    else
                        cout << '#';
                }
            }
            cout << endl;
        }

        cout << endl;

    }

    return 0;

}

