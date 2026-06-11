#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;

int main(){
    int n,k,r,s,p;
    string t;
    cin >> n >> k >> r >> s >> p >> t;
    vector<char> hand(n,'n');
    int ans=0;
    for(int i=0;i<n;i++){
        int point;
        char now_hand;
        if(t[i]=='r'){
            point=p;
            now_hand='p';
        }else if(t[i]=='s'){
            point=r;
            now_hand='r';
        }else if(t[i]=='p'){
            point=s;
            now_hand='s';
        }
        if(i-k>=0&&hand[i-k]==now_hand){
            point=0;
            now_hand='n';
        }
        ans+=point;
        hand[i]=now_hand;
    }
    cout << ans << endl;
}