#include <bits/stdc++.h>
using namespace std;
/*2進数配列+1*/
vector<int> two(vector<int> v, int N){
    v[N-1]+=1;
    int ind = N-1;
    int j=N-1;
    for(j=N-1;j>=1;j--){
        //cout << j << endl;
        if(v[j]>1){
            v[j-1]+=1;
            v[j]=0;
        }
    }
    /*for(j=0;j<N;j++){
        cout << "v" << v[j];
    }
    cout << endl;*/
    return v;
}

int main() {
    int N;
    cin >> N;
    vector<int> w(N);
    int T=0,sum;
    for(int i=0;i<N;i++){
        cin >> w[i];
        T += w[i];
    }
    sum = T;
    T /= 2;
    int S11=0,S21=0,S12=0,S22=0,ans=0,ans1=0,ans2=0;
    for(int i=0;i<N;i++){
        S11+=w[i];
        if(T<=S11){
            break;
        }
    }
    S21 = sum - S11;
    reverse(w.begin(),w.end());
    for(int i=0;i<N;i++){
        S22+=w[i];
        if(T<=S22){
            break;
        }
    }
    S12 = sum - S22;
    ans1 = abs(S11-S21);
    ans2 = abs(S22-S12);
    if(ans1>ans2){
        ans = ans2;
    }else{
        ans = ans1;
    }
    cout << ans << endl;
}