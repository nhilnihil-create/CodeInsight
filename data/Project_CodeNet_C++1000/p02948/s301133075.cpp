#include <bits/stdc++.h>
using namespace std;
#define int long long
using vec_int = vector<int>;
using P = pair<int,int>;
using T = tuple<int,int,int>;
using ll = long long;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

int charToInt(char c){
    char zero_num = '0';
    return (int)c - (int)zero_num;
}

signed main(){
    int N, M; cin>>N>>M; //N個のタスク、 M日後
    vec_int A(N), B(N);
    rep(i, N)cin>>A.at(i)>>B.at(i); //A日後に報酬B

    vector<P> vec_income(N);
    rep(i,N){
        vec_income.at(i) = make_pair(A.at(i),B.at(i));
    }
    sort(vec_income.begin(), vec_income.end());
    
    int index = 0;
    priority_queue<int> pq;
    int tot_money = 0;
    for(int i=1;i<M+1;i++){
        while(true){
            if(index==N)break;
            int Aval, Bval;
            tie(Aval, Bval) = vec_income.at(index);
            if(Aval<=i){
                pq.push(Bval);
                index++;
            }else{
                break;
            }
        }
        if(pq.size()==0)continue;
        int money = pq.top();pq.pop();
        tot_money += money;
    }
    cout<<tot_money<<endl;












    return 0;
}