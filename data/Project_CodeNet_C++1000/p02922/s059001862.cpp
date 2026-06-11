#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define forin(in) for(int i=0; i<(int)in.size(); i++) cin>>in[i]
#define forout(out) for(int i=0; i<(int)out.size(); i++) cout<<out[i]<<endl
#define rep(i, n) for(int i=0; i<(n); i++)

int main(){
    int A, B; cin >> A >> B;
    int sum = 1;
    int cnt = 0;
    while(true){
        if(sum >= B){
            cout<< cnt << endl;
            return 0;
        }
        sum = sum + A - 1;
        cnt++;
        if(sum >= B){
            cout<< cnt << endl;
            return 0;
        }
    }
}
