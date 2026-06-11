#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int N;
vector<int> A;

int buy(int start){
    for(int i=start;i<N-1;i++){
        if(A[i]<A[i+1])return i;
    }
    return -1;
}

int sell(int start){
    for(int i=start;i<N-1;i++){
        if(A[i+1]<A[i])return i;
    }
    return N-1;
}

ll update_balance(ll balance,int buyday,int sellday){
    return balance%A[buyday]+(balance/A[buyday])*A[sellday];
}

int main()
{
    cin >> N;
    A=vector<int>(N,0);
    ll res = 1000;
    for (int i = 0; i < N; i++){
        cin>>A[i];
    }
    for(int i=0;i<N;i++){
        int buyday=buy(i);
        if(buyday==-1)break;
        int sellday=sell(buyday);
        res = update_balance(res,buyday,sellday);
        i=sellday;
    }
    cout << res << endl;
}