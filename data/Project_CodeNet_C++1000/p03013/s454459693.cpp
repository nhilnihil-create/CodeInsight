#include <bits/stdc++.h>
using namespace std;
/*2進数配列+1*/
vector<int> twoadd(vector<int> v, int N){
    v[N-1]+=1;
    int ind = N-1;
    int j=N-1;
    for(j=N-1;j>=1;j--){
        if(v[j]>1){
            v[j-1]+=1;
            v[j]=0;
        }
    }
    return v;
}
/*ここから*/
long long search1(long long d){
    long long count = 0;
    long long f1 = 1;
    long long f2 = 2;
    long long temp;
    if(d == 1){
        count = f1;
    }else if(d == 2){
        count = f2;
    }else if(d==0){
        count = 1;
    }else{
        for(int i=0;i<d-2;i++){
            temp = f1%1000000007+f2%1000000007;
            f1 = f2;
            f2 = temp;
        }
        count = temp;
    }
    return count;
}

int main() {
    int N,M;
    cin >> N >> M;
    long long ans = 1;
    if(M==0){
        ans = search1(N)%1000000007;
        cout << ans << endl;
        exit(0);
    }
    vector<long long> a(M);
    for(int i=0;i<M;i++){
        cin >> a[i];
        if(i>0&&a[i-1]+1==a[i]){
            cout << 0 << endl;
            exit(0);
        }
    }
    long long temp = 0;
    for(int i=0;i<M;i++){
        temp = a[i]-temp-1;
        //cout << temp << endl;
        if(temp != 0){
            ans *=search1(temp);
        }
        //cout << search(temp) << endl;
        temp = a[i]+1;
        ans %= (long long)1000000007;
    }
    ans *= search1(N-a[M-1]-1);
    //cout << search(N-a[M-1]-1) << endl;
    ans%=(long long)1000000007;
    cout << ans << endl;
}