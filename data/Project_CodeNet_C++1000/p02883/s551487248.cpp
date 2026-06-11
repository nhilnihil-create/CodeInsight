#include <bits/stdc++.h>
using namespace std;
#define int long long
using vec_int = vector<int>;
using P = pair<int,int>;
using T = tuple<int,int,int>;
using ll = long long;
using vec_ll = vector<ll>;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

int charToInt(char c){
    char zero_num = '0';
    return (int)c - (int)zero_num;
}

signed main(){
    ll N, K; cin>>N>>K;
    vec_int A(N), F(N);
    rep(i,N)cin>>A.at(i);
    rep(i,N)cin>>F.at(i);

    sort(A.begin(),A.end());
    sort(F.begin(),F.end());

    //よし、二分探索だ
    ll left = -1;
    ll right = pow(10,18); 

    while(right>left+1){
        ll comp = (left+right)/2;
//        cout<<right<<" "<<left<<" "<<comp<<endl;

        //compのスコアを達成できるかをチェックする
        ll used_K = 0;
        int flag = 0;
        rep(i,N){
            if(F.at(N-1-i)*A.at(i)>comp){
                used_K+=(F.at(N-1-i)*A.at(i)-comp)/F.at(N-1-i);
                if((F.at(N-1-i)*A.at(i)-comp)%F.at(N-1-i)!=0)used_K++;
            }
            if(used_K>K){
                flag=1;
                break;
            }
        }
        //flag=1の時にはスコアを達成できなかった
        if(flag==1){
            left = comp; 
        }else{
            right = comp;
        }
    }
    cout<<right<<endl;


    return 0;
}