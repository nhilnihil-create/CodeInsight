#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
#define ll long long

class Dice{
    public:
    int val[6];

    Dice(int a[]){
        copy(a,a+6,val);
    }

    int side(){
        return val[2];
    }

    bool match(int f, int u){
        return (val[0] == f && val[4] == u); 
    }

    void move(char c){
        if(c == 'N') {
            int tmp = val[0];
            val[0] = val[1];
            val[1] = val[5];
            val[5] = val[4];
            val[4] = tmp;
        }
        if(c == 'W') {
            int tmp = val[1];
            val[1] = val[3];
            val[3] = val[4];
            val[4] = val[2];
            val[2] = tmp;
        }
        if(c == 'E') {
            int tmp = val[1];
            val[1] = val[2];
            val[2] = val[4];
            val[4] = val[3];
            val[3] = tmp;
        }
        if(c == 'S') {   
            int tmp = val[0];
            val[0] = val[4];
            val[4] = val[5];
            val[5] = val[1];
            val[1] = tmp;
        }
    }
};

int main() {
    string str = "WWWWNWWWWWSWWWWSSWWWWNWWWWWSWWWW";
    int a[6],q;
    rep(i,6) cin >> a[i];
    Dice d(a);
    cin >> q;
    rep(i,q){
        int u,f;
        cin >> u >> f;
        for(auto &s : str){
            d.move(s);
            if(d.match(f,u)) {
                cout << d.side() << endl;
                break;
            }
        }
    }
    return 0;
}
