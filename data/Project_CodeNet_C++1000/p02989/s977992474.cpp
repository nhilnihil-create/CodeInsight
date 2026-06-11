#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
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

/*フィボナッチ*/
long long fibonatti(long long d){
    long long count = 0;
    long long f1 = 1;
    long long f2 = 1;/*ここを変える*/
    long long temp;
    if(d == 1){
        count = f1;
    }else if(d == 2){
        count = f2;
    }else if(d==0){
        count = 1;
    }else{
        for(int i=0;i<d-2;i++){
            temp = f1+f2;
            f1 = f2;
            f2 = temp;
        }
        count = temp;
    }
    return count;
}

/*最大公約数*/
unsigned long long GCD(long long L,long long R){
    if(L>R){
        long long temp=R;
        R = L;
        L = temp;
    }
    unsigned long long pp=0,ppt=0;
    unsigned long long ans=0;
    if(R%L==0){
        ans = L;
    }else{
        while(true){
            ppt = pp;
            pp=R%L;
            if(pp == 0){
                ans = ppt;
                break;
            }
            R = L;
            L = pp;
        }
    }    
    return ans;    
}

/*最小公倍数*/
unsigned long long LCM(long long L,long long R){
    unsigned long long ans;
    unsigned long long gcd = GCD(L,R);
    ans = (L/gcd)*R;
    return ans;
}

/*ここから*/
int main() {
    int N;
    cin >> N;
    vector<int> d(N);
    for(int i=0;i<N;i++){
        cin >> d[i];
    }
    sort(d.begin(),d.end());
    int df,da;
    df = d[N/2-1];
    da = d[N/2];
    cout << da-df << endl;
}