#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)n; i++)
#define ll long long

int main(){
    int n,m;
    cin >> n >> m;
    vector<int> clear(n+1),wrong(n+1);
    int ac=0,wa=0;
    rep(i,m){
        int num;
        string s;
        cin >> num >> s;
        if(s == "AC"){
            if(clear.at(num)==0){
                clear.at(num)=1;
                ac++;
                wa += wrong.at(num);
            }
        }else{
            if(clear.at(num)!=1){
                wrong.at(num)++;
            }
        }
    }
    cout << ac << " " << wa << endl;
}
