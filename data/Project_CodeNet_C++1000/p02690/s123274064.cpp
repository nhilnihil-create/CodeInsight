#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define forin(in) for(int i=0; i<(int)in.size(); i++) cin>>in[i]
#define forout(out) for(int i=0; i<(int)out.size(); i++) cout<<out[i]<<endl
#define rep(i, n) for(int i=0; i<(n); i++)

int main(){
    int X; cin >> X;

    for(int i = -200; i <= 200; i++){
        for(int j = -200; j <= 200; j++){
            if(pow(i, 5) - pow(j, 5) == X){
                cout<< i << " " << j << endl;
                return 0;
            }
        }
    }
}
