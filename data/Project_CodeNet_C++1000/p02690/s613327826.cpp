#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define forin(in) for(int i=0; i<(int)in.size(); i++) cin>>in[i]
#define forout(out) for(int i=0; i<(int)out.size(); i++) cout<<out[i]<<endl
#define rep(i, n) for(int i=0; i<(n); i++)

int main(){
    int X; cin >> X;

    for(int A = -150; A <= 150; A++){
        for(int B = -150; B <= 150; B++){
            if(pow(A, 5) - pow(B, 5) == X){
                cout<< A << " " << B << endl;
                return 0;
            }
        }
    }
}