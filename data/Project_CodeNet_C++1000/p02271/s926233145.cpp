#include <bits/stdc++.h>

#define MAX 2000

using namespace std;

int n,q;
int n_lst[MAX],q_lst[MAX];
static int ans_lst[MAX][MAX];


bool bf(int idx,int x){
    if(x == 0) return true;
    if(idx < n){
        return bf(idx+1,x) || bf(idx+1,x-n_lst[idx]);
    }
    return false;
}

int m_bf(int idx,int x){
    //1:false,2:true

    //定義済み？
    if(ans_lst[idx][x] > 0) return ans_lst[idx][x];


    if(x == 0) ans_lst[idx][x] = 2;
    else if(idx < n){
        if(m_bf(idx+1,x-n_lst[idx]) == 2)
            ans_lst[idx][x] = 2;
        else if(m_bf(idx+1,x) == 2)
            ans_lst[idx][x] = 2;
    }
    else
        ans_lst[idx][x] = 1;

    return ans_lst[idx][x];

}

int main(){
    cin >> n;
    for(int i=0;i<n;i++) cin >> n_lst[i];
    cin >> q;
    for(int i=0;i<q;i++) cin >> q_lst[i];

    for(int i=0;i<q;i++){
        if(m_bf(0,q_lst[i]) == 2)
            cout << "yes" << endl;
        else
            cout << "no" << endl;
    }
}

