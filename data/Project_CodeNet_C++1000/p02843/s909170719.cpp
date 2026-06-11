#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)

int main() {
    int x;
    cin>>x;
    int y;
    rep(i,(x/105)+2){
        y=x-(105*i);
        rep(j,(y/104)+2){
            y=x-(105*i)-(104*j);
            rep(k,(y/103)+2){
                y=x-(105*i)-(104*j)-(103*k);
                rep(l,(y/102)+2){
                    y=x-(105*i)-(104*j)-(103*k)-(102*l);
                    rep(m,(y/101)+2){
                        y=x-(105*i)-(104*j)-(103*k)-(102*l)-(101*m);
                        if(y%100==0 && y>=0){
                            cout<<1<<endl;
                            return 0;
                        }
                    }
                }
            }
        }
    }
    cout<<0<<endl;
}